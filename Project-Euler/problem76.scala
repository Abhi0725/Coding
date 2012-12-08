object ProjectEuler {
  def howManySums(n : Int) : Int = {
    val dp = Array.tabulate(n+1, n+1)((i,_) => if (i == 0) 1 else 0)
    for (i <- 1 to n; j <- 1 to n; k <- 1 to math.min(i, j)) {
      dp(i)(j) = dp(i)(j) + dp(i-k)(k)
    }
    dp(n)(n-1)
  }

  def main(args: Array[String]) {
    val n = 100
    System.out.println("There are " + howManySums(n) + " different ways to write " + n +
                       " as a sum of at least two positive integers")
  }
}
