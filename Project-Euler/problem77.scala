import PELib._

object ProjectEuler {
  def main(args: Array[String]) {
    val target = 5000
    val limit = 2048
    val sieve = new PELib.Sieve(limit)
    val how_many = new Array[Int](limit)
    how_many(0) = 1
    for (i <- (2 until limit).filter(sieve.isPrime(_));
         j <- (limit-1 to 0 by -1).filter(how_many(_) != 0);
         k <- j+i until limit by i)
      how_many(k) = how_many(k) + how_many(j)

    (1 until limit).find(how_many(_) > target) match {
      case Some(n) => System.out.println(n + " is the first number that can be written is the sum of primes in over " + target + " ways")
      case None => throw new Error("Limit of " + limit + " is enough to find the solution.")
    }
  }
}
