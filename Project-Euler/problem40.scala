object ProjectEuler {
  def get_digit_in_number(d: Int, n: Int) : Int =
    if (d == 0) n%10
    else get_digit_in_number(d-1, n/10)

  def get_digit(d: Int) : Int = {
    def rec(d: Int, base: Int, base_length: Int) : Int = {
      val n_base = base * 9 * base_length
      if (d > n_base) rec(d - n_base, 10*base, base_length + 1)
      else get_digit_in_number(base_length - d + (d-1)/base_length*base_length,
                               base + (d-1)/base_length)
    }
    rec(d, 1, 1)
  }

  def get_digits(digits: List[Int]) : List[Int] = {
    def rec(digits: List[Int], result: List[Int]) : List[Int] =
      digits match {
        case Nil => result
        case d::t => rec(t, get_digit(d)::result)
      }
    rec(digits, Nil).reverse
  }

  def check(n:Int) : String = {
    def gen_list(n: Int, r: List[Int]) : List[Int] =
      if (n == 0) r
      else gen_list(n-1, n::r)
    val l = gen_list(n, Nil)
    val digits = get_digits(l)
    digits.mkString("")
  }

  def main(args: Array[String]) {
    val digits = get_digits(List(1, 10, 100, 1000, 10000, 100000, 1000000))
    System.out.println("Digits: " + digits.mkString(", "))
    System.out.println("Product: " + digits.foldLeft(1)(_ * _)
  }
}
