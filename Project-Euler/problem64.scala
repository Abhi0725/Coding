import PELib._

object ProjectEuler {
  def gcd3(a : Int, b : Int, c : Int) =
    PELib.gcd(PELib.gcd(math.abs(a), math.abs(b)), math.abs(c))

  def representation(number : Int) : List[Int] = {
    val sqrt = math.sqrt(number)
    def invert(A : Int, B : Int, C : Int) : (Int, Int, Int) = {
      // (A*sqrt(number) + B) / C  --> C / (A*sqrt(number) + B)
      val denominator = A*A*number - B*B
      val div : Int = gcd3(C*A, C*B, denominator)
      (C*A/div, -C*B/div, denominator/div)
    }
    def f(A : Int, B : Int, C : Int, seen : Set[(Int, Int, Int)]) : List[Int] = {
      // (A*sqrt(number) + B) / C
      if (seen contains (A, B, C)) Nil
      else {
        val floor : Int = math.floor((A * sqrt + B) / C).toInt
//        System.out.println("( " + A + "*sqrt(" + number + ") + " + B + " )/" + C
//                           + "   --> " + floor)
        val (a, b, c) = invert(A, B - floor*C, C)
        floor :: f(a, b, c, seen + ((A,B,C)))
      }
    }
    val floor : Int = math.floor(sqrt).toInt
    if (floor * floor == number) List(floor)
    else {
      floor :: f(1, floor, number - floor*floor, Set())
    }
  }

  def main(args: Array[String]) {
    val n = 10000
    val numbers = Stream.from(1).filterNot(PELib.perfectSquare).takeWhile(_ <= n)
    val how_many = numbers.count(i => (representation(i).length - 1) % 2 == 1)
    System.out.println(how_many)
  }
}
