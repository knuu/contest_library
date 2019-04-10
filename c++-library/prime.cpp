struct Prime {
  vector<bool> sieve;
  vector<int> primes;
  Prime(int N) {
    assert(N >= 1);
    sieve.resize(N+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= N; i++) {
      if (sieve[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= N; j += i) sieve[j] = false;
      }
    }
  }
};
