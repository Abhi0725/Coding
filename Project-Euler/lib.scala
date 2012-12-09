package PELib

object PELib {
  def getDigits(n : BigInt) : List[Int] = {
    def f(n : BigInt, r : List[Int]) : List[Int] =
      if (n == 0) r
      else f(n/10, (n%10).toInt :: r)
    f(n, Nil)
  }
  
  def digitsToNumber(digits : List[Int]) : BigInt =
    digits.foldLeft(BigInt(0))(10 * _ + _)

  def gcd(a : Int, b : Int) : Int =
    if (b == 0) a
    else gcd(b, a % b)

  def perfectSquare(n : Int) : Boolean = {
    val sqrt = math.sqrt(n).toInt
    if (sqrt * sqrt == n) true
    else false
  }

  class Sieve(limit : Int) {
    val primes = Array.tabulate(limit)(i => i != 0 && i != 1)
    for (i <- primes.indices if primes(i))
      for (j <- i * i.asInstanceOf[Long] until primes.length by i if (i * i) > 0)
        primes(j.toInt) = false

    def isPrime(n : Int) : Boolean = {
      if (n < primes.length) primes(n)
      else {
        val limit = math.sqrt(n).toInt
        val is_not_prime = primes.indices.take(limit).exists(i => primes(i) && n % i == 0)
        if (is_not_prime) false
        else {
          val hard_limit = (primes.length - 1).asInstanceOf[Long] * (primes.length - 1)
          if (n <= hard_limit) true
          else throw new Error("Out of range: " + n + " (fast limit = " + limit + ", limit = " + hard_limit + ")")
        }
      }
    }
  }

  class PartitionFunction(limit : Int, modulo : Long) {
    val p : Array[Long] = new Array(limit + 1)

    // Using Euler's generating function to precompute the values.
    p(0) = 1
    val mult = Stream.from(1).map(i => if (i % 2 != 0) 1 else -1)
    val pent1 = Stream.from(1).map(i => i*(3*i - 1)/2)
    val pent2 = Stream.from(1).map(i => i*(3*i + 1)/2)
    val data = mult zip (pent1 zip pent2)
    for (n <- 1 to limit) {
      val valid_data = data.takeWhile{case (_,(p1,_)) => p1 <= n}
      p(n) = valid_data.foldLeft(0 : Long) {
        case (sum, (mult, (p1, p2))) if (p2 > n) => (sum + mult*p(n - p1)) % modulo
        case (sum, (mult, (p1, p2))) => (sum + mult*(p(n - p1) + p(n - p2))) % modulo
      }
    }

    def apply(n : Int) : Long =
      if (n <= limit) p(n)
      else throw new Error("Out of range: " + n + " (limit = " + limit + ")")
  }
}
