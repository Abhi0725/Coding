object ProjectEuler {
  def all_powers(limit : Int) : List[List[BigInt]] = {
    val first_line : List[BigInt] = (1 until limit) map (BigInt(_)) toList
    def next_line(line : List[BigInt]) : List[BigInt] =
      first_line zip line map {case (x, y) => x * y}
    def f(i : Int, curr : List[BigInt], r : List[List[BigInt]]) : List[List[BigInt]] =
      if (i > limit) r
      else f(i+1, next_line(curr), curr :: r)
    f(0, first_line, Nil)
  }

  def sum_digits(n : BigInt) : Int = {
    def f(n : BigInt, total : Int) : Int =
      if (n > 0) f(n / 10, total + (n%10).toInt)
      else total
    f(n, 0)
  }

  def main(args: Array[String]) {
    System.out.println(all_powers(100).map(_ map sum_digits max).max);
  }
}
