object ProjectEuler {
  def nDigits(n : BigInt) : Int = {
    def f(n : BigInt, r : Int) : Int =
      if (n > 0) f(n/10, r+1)
      else r
    f(n, 0)
  }

  def powers(n : Int) : Stream[(Int, BigInt)] = {
    def f(i : Int, curr : BigInt) : Stream[(Int, BigInt)] = (i, curr) #:: f(i+1, curr * n)
    f(1, n)
  }

  def main(args: Array[String]) {
    val all_numbers = (1 to 10) map (powers(_) takeWhile {case (i, pow) => i == nDigits(pow)} map (_._2) toList)
    val numbers : Set[BigInt] = all_numbers.foldLeft(Set[BigInt]())(_ ++ _)
    System.out.println("All n-digit positive numbers that are also an nth power: " + numbers.toList.sorted)
    System.out.println("Total: " + numbers.size + " numbers.")
  }
}
