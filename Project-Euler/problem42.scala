object ProjectEuler {
  def wordValue(word: String) : Int =
    word.toList.foldLeft(0)((v, c) => v + c.toInt - 'A'.toInt + 1)

  def getWords(input: scala.io.BufferedSource) : List[String] = {
    def parseLine(line: String): List[String] =
      line.split(",").toList.map((w) => w.filter((c) => c >= 'A' && c <= 'Z'))
    input.getLines.toList.foldLeft(List[String]())((acc, line) => acc ++ parseLine(line))
  }

  def is_triangle(n: Int) : Boolean = {
    val d = 1 + 8*n
    val d_sqrt = math.sqrt(d.doubleValue)
    (d_sqrt * d_sqrt == d) && (d_sqrt % 2 == 1)
  }

  def main(args: Array[String]) {
    val words = getWords(io.Source.stdin);
    val n_triangle_words =
      words.map(wordValue).filter(is_triangle).length
    System.out.println(n_triangle_words + " are triangle words (out of " + words.length + " words)")
  }
}
