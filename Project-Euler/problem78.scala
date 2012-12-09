import PELib._

object ProjectEuler {
  def main(args: Array[String]) {
    val limit = 60000
    val partition = new PELib.PartitionFunction(limit, 1000000)
    val solution : Option[Int] = (1 to limit).find(i => partition(i) == 0)
    solution match {
      case Some(sol) => System.out.println(sol)
      case None => throw new Error(":-(")
    }
  }
}
