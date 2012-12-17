import PELib._

object ProjectEuler {
  def main(args: Array[String]) {
    val limit = 12000
    val target_low = 1.0 / 3
    val target_high = 1.0 / 2
    val count_for_each_n = for (n <- 2 to limit) yield {
      val lower_bound = math.floor(n * target_low).toInt + 1
      val upper_bound = math.ceil(n * target_high).toInt - 1
      (upper_bound to lower_bound by -1).count(PELib.gcd(_, n) == 1)
    }
    System.out.println("There are " + count_for_each_n.sum + " reduced proper fractions "
                       + "between " + target_low + " and " + target_high + ".")
  }
}
