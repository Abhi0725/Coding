object Sieve {
  import scala.collection.immutable.HashSet

  def ints(i: Int): Stream[Int] =
    Stream.cons(i, ints(i+1))

  def primes(numbers: Stream[Int]): Stream[Int] =
    Stream.cons(numbers.head,
                primes(numbers.tail filter (i => i % numbers.head != 0)))

  def primes_list(n: Int) : List[Int] =
    primes(ints(2)) take n toList
}

object ProjectEuler {
  def primorial(primes: List[Int], limit: Int): Int = {
    def rec(primes: List[Int], product: Int): Int =
      primes match {
        case Nil => throw new Error("Not enough primes")
        case p::t =>
          if (p * product <= limit) rec(t, p * product)
          else product
      }
    rec(primes, 1)
  }

  def main(args: Array[String]) {
    val primes = Sieve.primes_list(100)
    System.out.println(primorial(primes, 1000000))
  }
}
