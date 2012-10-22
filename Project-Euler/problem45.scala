// Idea:
//   For each hexagonal number, test if it is pentagonal.
//   All hexagonal numbers are triangle.
// Note:
//   next(143 + 1) or next_number(40755) are two solutions.

object ProjectEuler {
  def hexagonal(n: BigInt) : BigInt =
    n*(2*n-1)

  def is_pentagonal(n: BigInt) : Boolean = {
    val d = 1 + 24*n
    val d_sqrt = math.sqrt(d.doubleValue)
    (d_sqrt * d_sqrt == d) && (d_sqrt % 6 == 5)
  }

  def next(n: BigInt) : BigInt = {
    val h = hexagonal(n)
    if (is_pentagonal(h)) h
    else next(n+1)
  }

  def main(args: Array[String]) {
    System.out.println(next(143 + 1))
  }
}
