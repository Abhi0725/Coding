object ProjectEuler {
  def invert_number(n: BigInt): BigInt = {
    def rec(n: BigInt, result: BigInt) : BigInt =
      if (n == 0) result
      else rec(n/10, result*10 + n%10)
    rec(n, 0)
  }

  def Lychrel(n: BigInt, limit: Int): Boolean = {
    def rec(n: BigInt, iter: Int): Boolean = {
      var in = invert_number(n)
      if (iter > limit) true
      else if (in == n) false
      else rec(n + in, iter + 1)
    }
    rec(n + invert_number(n), 1)
  }

  def CountLychrel(range_start: Int, range_end: Int, limit: Int): Int = {
    def rec(i: Int, r: Int): Int =
      if (i >= range_end) r
      else if (Lychrel(i, limit)) rec(i + 1, r + 1)
      else rec(i + 1, r)
    rec(range_start, 0)
  }

  def main(args: Array[String]) {
    System.out.println(CountLychrel(1, 10000, 50))
  }
}
