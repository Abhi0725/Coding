import PELib._

object ProjectEuler {
  def euler : Stream[BigInt] = {
    def f(i: BigInt) : Stream[BigInt] = 1 #:: (2*i) #:: 1 #:: f(i+1)
    BigInt(2) #:: f(BigInt(1))
  }

  def nthContinuedFraction(fraction : Stream[BigInt], n : Int) : (BigInt, BigInt) = {
    def f(fraction : List[BigInt], num : BigInt, denom : BigInt) : (BigInt, BigInt) =
      fraction match {
        case x::xs => f(xs, denom + x*num, num)
        case Nil => (num, denom)
      }
    f(fraction.take(n).toList.reverse, BigInt(1), BigInt(0))
  }

  def main(args: Array[String]) {
    val n = 100
    val (a, b) = nthContinuedFraction(euler, n)
    System.out.println(n + "th convergent: " + a + "/" + b)
    System.out.println("Sum of digits in the numerator: " + PELib.getDigits(a).foldLeft(0)(_ + _))
  }
}
