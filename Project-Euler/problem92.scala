object ProjectEuler {
  def next(n : Int) : Int = {
    def f(n : Int, total : Int) : Int =
      if (n > 0) f(n / 10, total + (n%10)*(n%10))
      else total
    f(n, 0)
  }

  def find_endings(limit : Int) : Array[Int] = {
    val endings = new Array[Int](limit)
    endings(1) = 1; endings(89) = 89
    def f(n : Int) : Int =
      if (n < endings.length && endings(n) != 0) return endings(n)
      else if (n >= endings.length) return f(next(n))
      else {
        val r = f(next(n))
        endings(n) = r
        return r
      }
    for (i <- 1 until limit) f(i)
    return endings
  }

  def main(args: Array[String]) {
    val limit = 10000000
    val endings = find_endings(limit)
    System.out.println(endings.count(_ == 89))
  }
}
