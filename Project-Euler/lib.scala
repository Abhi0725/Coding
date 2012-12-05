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
}
