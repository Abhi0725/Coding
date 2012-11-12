object ProjectEuler {
  val romanChar : Map[List[Char], Int] =
    Map(List('I') -> 1, List('V') -> 5, List('X') -> 10, List('L') -> 50, List('C') -> 100, List('D') -> 500, List('M') -> 1000)
  val validCombinations : Set[List[Char]] =
    Set(List('I','V'), List('I','X'), List('X', 'L'), List('X', 'C'), List('C', 'D'), List('C', 'M'))
  val romanSubtractiveCombination : Map[List[Char], Int] =
    for {(c, ci) <- romanChar; (d, di) <- romanChar; if (ci < di && validCombinations.contains(c ++ d))} yield (c ++ d) -> (di - ci)

  def romanToInt(roman: String): Int = {
    def find(roman_str: String, roman_map: Map[List[Char], Int]) : Option[(List[Char], Int)] =
      roman_map.find{case (seq, value) => roman_str.startsWith(seq)}
    def f(roman: String, r: Int) : Int = {
      if (roman.isEmpty) r
      else find(roman, romanSubtractiveCombination) match {
        case Some((comb, value)) => f(roman.drop(comb.size), value + r)
        case None => find(roman, romanChar) match {
          case Some((_, value)) => f(roman.tail, value + r)
          case _ => throw new Error("Invalid case converting roman to int")
        }
      }
    }
    f(roman, 0)
  }

  val romanMapping : List[(List[Char], Int)] =
    (romanChar ++ romanSubtractiveCombination).toList.sortBy{case (_, value) => -value}
  def intToMinimalRoman(n : Int) : String = {
    def f(n : Int, best : List[Char], r : List[Char], sup : Int) : List[Char] = {
      if (best.size <= r.size + n/sup) best
      else if (n == 0) r
      else {
        val valid_prefix : List[(List[Char], Int)] = romanMapping.filter{case (_, value) => value <= n && value <= sup}
        valid_prefix.foldLeft(best){case (best, (seq, value)) =>
          f(n - value, best, r ++ seq, if (seq.size > 1) value - 1 else value)}
      }
    }
    f(n, List.fill(n){'I'}, Nil, romanMapping.head._2).mkString
  }

  def main(args: Array[String]) {
    val roman_numbers = io.Source.stdin.getLines.toList
    val numbers = roman_numbers map romanToInt
    val minimal_roman_numbers = numbers map intToMinimalRoman
    val deltas = for {(roman, minimal_roman) <- roman_numbers zip minimal_roman_numbers} yield (roman.length - minimal_roman.length)
    val delta = deltas.reduce(_ + _)
    System.out.println("Chars saved = " + delta)
  }
}
