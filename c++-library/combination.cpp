template <typename T>
T powmod(T n, T k, T mod) {
  if (k == 0) {
    return 1;
  } else if (k % 2 == 0) {
    return powmod(n * n % mod, k / 2, mod);
  } else {
    return n * powmod(n, k-1, mod) % mod;
  }
}

template <typename T>
T inv(T x, T mod) {
  return powmod(x, mod-2, mod);
}

template <typename T>
T comb(T n, T k, T mod) {
  assert (0 <= k && k <= n);
  T ret = 1;
  for (T i = 0; i < k; i++) {
    ret *= n - i;
    ret %= mod;
    ret *= inv(i+1);
    ret %= mod;
  }
  return ret;
}
