// This solution generates all the diagonals numbers in a stream.
// The C solution is more direct and iterates only once keeping only the current value.

class Sieve(limit : Int) {
  val primes = Array.tabulate(limit)(i => i != 0 && i != 1)
  for (i <- primes.indices if primes(i))
    for (j <- i * i.asInstanceOf[Long] until primes.length by i if (i * i) > 0)
      primes(j.toInt) = false
  def isPrime(n : Int) : Boolean = {
    if (n < primes.length) primes(n)
    else {
      val limit = math.sqrt(n).toInt
      val is_not_prime = primes.indices.take(limit+2).exists(i => primes(i) && n % i == 0)
      if (is_not_prime) false
      else {
        val hard_limit = (primes.length - 1).asInstanceOf[Long] * (primes.length - 1)
        if (n <= hard_limit) true
        else throw new Error("Out of range: " + n + " (fast limit = " + limit + ", limit = " + hard_limit + ")")
      }
    }
  }
}

object ProjectEuler {
  def spiralDiagonals : Stream[List[Int]] = {
    def diagonals(last: Int, inc: Int) : Stream[List[Int]] =
      (1 to 4 map (last + _ * inc) toList) #:: diagonals(last + 4 * inc, inc + 2)
    diagonals(1, 2)
  }

  def findAnswer(diagonals : Stream[List[Int]], proportion : Double) : Int = {
    val sieve = new Sieve(1024 * 1024)
    def f(diagonals : Stream[List[Int]], i : Int, prev_n_primes : Int) : Int = {
      val n_primes = prev_n_primes + diagonals.head.count(sieve.isPrime _)
      val total_numbers = 4 * i + 1
      val ratio = n_primes * 1.0 / total_numbers
      System.out.println("i = " + i + ", n_primes = " + n_primes + ", n_numbers = " + total_numbers +
                         ", curr ratio = " + ratio + ".")
      if (ratio < proportion) 1 + 2 * i
      else f(diagonals.tail, i + 1, n_primes)
    }
    f(diagonals, 1, 0)
  }

  def main(args: Array[String]) {
    val limit = 0.1
    System.out.println(findAnswer(spiralDiagonals, limit))
  }
}
