object ProjectEuler {
  def continuedFractionIterations : Stream[(BigInt, BigInt)] = {
    def f(a: BigInt, b: BigInt) : Stream[(BigInt, BigInt)] =
      (a,b) #:: f(a + 2*b, a + b)
    f(3, 2)
  }

  def nDigits(n : BigInt) : Int = {
    def f(n : BigInt, r : Int) : Int =
      if (n > 0) f(n/10, r+1)
      else r
    f(n, 0)
  }

  def main(args: Array[String]) {
    val fractions = continuedFractionIterations
    val count : Int = (fractions take 1000 filter {case (a,b) => nDigits(a) > nDigits(b)}).length
    System.out.println(count)
  }
}
