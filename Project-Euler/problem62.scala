import PELib._

object ProjectEuler {
  def ints(i: Int) : Stream[Int] = i #:: ints(i+1)

  type Number = List[Int]

  def canonical(number : Number) : Number =
    number.sorted

  def findSolution(n_permutations : Int) : BigInt = {
    def collectOccurrence(occ : Map[Number, List[Number]], cube : Number) : Map[Number, List[Number]] = {
      val c = canonical(cube)
      occ.updated(c, cube :: occ.getOrElse(c, Nil))
    }
    def collectOccurrences(cubes : Stream[List[Int]]) : Map[Number, List[Number]] =
      cubes.foldLeft(Map[Number, List[Number]]())(collectOccurrence)
    def findSolutionWithNDigits(cubes : Stream[List[Int]], n_digits : Int) : BigInt = {
      val (cubes_n_digits, cubes_more_digits) = cubes.span(_.length == n_digits)
      val occurrences = collectOccurrences(cubes_n_digits)
      val solutions = occurrences.filter(_._2.length == n_permutations)
      if (solutions.size > 0) {
        val all_numbers = solutions.valuesIterator.foldLeft(List[Number]())(_ ++ _)
        all_numbers.map(PELib.digitsToNumber).min
      } else findSolutionWithNDigits(cubes_more_digits, n_digits + 1)
    }
    val cubes = ints(1).map(i => PELib.getDigits(BigInt(i) pow 3))
    findSolutionWithNDigits(cubes, 1)
  }

  def main(args: Array[String]) {
    val n = 5
    System.out.println(findSolution(n) + " is the smallest cube for which " +
                       "exactly " + n + " permutation of its digits are cube.")
  }
}
