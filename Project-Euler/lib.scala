package PELib

object PELib {
  def ints(i: Int) : Stream[Int] = i #:: ints(i+1)

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
}
