object ProjectEuler {
  def combination : Stream[List[BigInt]] = {
    def next_perm(curr: List[BigInt]) : List[BigInt] = {
      val zero = List(BigInt(0))
      (curr ++ zero).zip(zero ++ curr).map{case (a, b) => a + b}
    }
    def comb(curr: List[BigInt]) : Stream[List[BigInt]] =
      Stream.cons(curr, comb(next_perm(curr)))
    comb(List(1))
  }

  def count(bottom_limit : BigInt, n_limit : Int, combination : Stream[List[BigInt]]) =
    combination.take(n_limit + 1).map(_.count(_ > bottom_limit)).foldLeft(0)(_ + _)

  def main(args: Array[String]) {
    System.out.println(count(1000000, 100, combination));
  }
}
