object ProjectEuler {
  def main(args: Array[String]) {
    val input : List[(Long, Long)] = io.Source.stdin.getLines.map{s =>
      val Array(b, e) = s.split(',')
      (b.toLong, e.toLong)}.toList
    val numbers = input.map{case (b, e) => e * math.log(b)}
    val solution = Stream.from(1).zip(numbers).maxBy(_._2)
    System.out.println("Line with the greatest value is " + solution._1 +
                       " (" + input(solution._1)._1 + "^" + input(solution._1)._2 + ")")
  }
}
