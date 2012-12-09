import PELib._

object ProjectEuler {
  // dp(i)(j): how many different ways to write i as a sum of integers <= j.
  def howManySums(n : Int) : Int = {
    val dp = Array.tabulate(n+1, n+1)((i,_) => if (i == 0) 1 else 0)
    for (i <- 1 to n; j <- 1 to n; k <- 1 to math.min(i, j)) {
      dp(i)(j) = dp(i)(j) + dp(i-k)(k)
    }
    dp(n)(n-1)
  }

  // The problem overview (.pdf) for problem 31 in Project Euler itself explains this solution.
  def howManySums2(n : Int) : Int = {
    val dp : Array[Int] = new Array(n + 1)
    dp(0) = 1
    for (i <- 1 to n; j <- i to n)
      dp(j) = dp(j) + dp(j-i)
    dp(n) - 1
  }

  def main(args: Array[String]) {
    val n = 100
    val solution1 = howManySums(n)
    val solution2 = howManySums2(n)
    val partition = new PELib.PartitionFunction(n, Long.MaxValue)
    val solution3 = partition(n) - 1
    System.out.println("There are " + solution1 + " different ways to write " + n +
                       " as a sum of at least two positive integers")
    System.out.println("Other solutions: " + solution2 + ", " + solution3)
  }
}
