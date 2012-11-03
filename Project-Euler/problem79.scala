object ProjectEuler {
  type Hint = List[Int]
  type Password = List[Int]

  def readInput(input: scala.io.BufferedSource) : List[Hint] =
    input.getLines.toList.map((l) => l.toList.map((c) => c.toInt - '0'))

  def firstNumbers(hints : List[Hint]) : Hint = {
    val count : Map[Int, Int] = hints.map((h) => h.head).groupBy(identity).mapValues((x) => x.size)
    count.toList.sortBy((x) => -x._2).map((x) => x._1)
  }

  def updateHints(number: Int, hints: List[Hint]) : List[Hint] = {
    def f(hints: List[Hint], r: List[Hint]) : List[Hint] =
      hints match {
        case Nil => r
        case Nil::t => f(t, r)
        case (hh::Nil)::t if hh == number => f(t, r)
        case (hh::ht)::t if hh == number => f(t, ht::r)
        case h::t => f(t, h::r)
      }
    f(hints, Nil)
  }

  def findCode(hints : List[Hint]) : Hint = {
    def try_number(number: Int, hints: List[Hint], best: Option[Password], r: Password): Password =
      rec(updateHints(number, hints), best, number :: r)
    def try_numbers(numbers: List[Int], hints: List[Hint], best: Option[Password], r: Password): Password =
      numbers match {
        case Nil => throw new Error("Invalid")
        case n::Nil => try_number(n, hints, best, r)
        case n::t => try_numbers(t, hints, Some(try_number(n, hints, best, r)), r)
      }
    def rec(hints : List[Hint], best: Option[Password], r: Password): Password =
      (hints, best) match {
        case (Nil, Some(b)) => if (b.size < r.size) b else r
        case (Nil, None) => r
        case (_, Some(b)) if b.size <= r.size + 1 => b  // cut
        case _ => try_numbers(firstNumbers(hints), hints, best, r)
      }
    rec(hints, None, Nil).reverse
  }

  def main(args: Array[String]) {
    val hints = readInput(io.Source.stdin);
    System.out.println(findCode(hints).mkString);
  }
}
