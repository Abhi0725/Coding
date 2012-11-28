object ProjectEuler {
  def pow_mod_n(a : BigInt, b : BigInt, n : BigInt) : BigInt = {
    def f(x : BigInt, b : BigInt, pow : BigInt) : BigInt =
      if (b == 0) pow
      else if (b % 2 == 1) f(x*x % n, b/2, pow*x % n)
      else f(x*x % n, b/2, pow)
    f(a % n, b, 1)
  }

  def main(args: Array[String]) {
    val n_digits = 10
    val mod = BigInt(10).pow(n_digits)
    System.out.println((28433 * pow_mod_n(2, 7830457, mod) + 1) % mod)
    // Or using just the BigInt library:
    System.out.println((28433 * BigInt(2).modPow(7830457, mod) + 1) % mod)
  }
}
