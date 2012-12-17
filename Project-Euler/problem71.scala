import PELib._

object ProjectEuler {
  def main(args: Array[String]) {
    val limit = 1000000
    val target = (3, 7)
    val closest_to_target = (limit to 2 by -1).foldLeft((0, 1)){
      case ((num, den), n) =>
        val upper_bound = math.ceil(target._1 * n * 1.0 / target._2).toInt - 1
        val lower_bound = math.floor(num * 1.0 * n / den).toInt + 1
        val better_numerator = (upper_bound to lower_bound by -1).find(PELib.gcd(_, n) == 1)
        better_numerator match {
          case Some(numerator) => (numerator, n)
          case None => (num, den)
        }
    }
    System.out.println("Up to d <= " + limit + ", the reduced proper fraction immediately to the left of "
                       + target._1 + "/" + target._2 + " is " + closest_to_target._1 + "/" + closest_to_target._2 + ".")
  }
}
