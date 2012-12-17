import PELib._

object ProjectEuler {
  def isBouncyNumber(n : Int) : Boolean = {
    val status = PELib.getDigits(n).foldLeft((true, 0, true, 9)){
      case ((s_i, min, s_d, max), digit) =>
        val new_s_i = if (digit < min) false else s_i
        val new_min = if (digit > min) digit else min
        val new_s_d = if (digit > max) false else s_d
        val new_max = if (digit < max) digit else max
        (new_s_i, new_min, new_s_d, new_max)
    }
    !status._1 && !status._3
  }

  def findProportion(numbers : Stream[Boolean], n : Int, prev_count_n_bouncy : Int) : Int = {
    val count_n_bouncy = if (numbers.head) prev_count_n_bouncy + 1 else prev_count_n_bouncy
    if (count_n_bouncy * 100 == n * 99) n
    else findProportion(numbers.tail, n+1, count_n_bouncy)
  }

  def main(args: Array[String]) {
    val is_bouncy : Stream[Boolean] = Stream.from(100).map(isBouncyNumber)
    System.out.println(findProportion(is_bouncy, 100, 0))
  }
}
