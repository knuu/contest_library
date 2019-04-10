template<typename T> struct RangeMaxQuery {
  int N, _N;
  vector<T> dat;
  T initial;

  RangeMaxQuery(int _N, T initial = 0) : _N(_N), initial(initial) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, initial);
  }

  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = max(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // [a, b)
  T query(int a, int b) {
    assert(0 <= a && a <= b && b <= _N);
    return query(a, b, 0, 0, N);
  }

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return initial;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return max(query(a, b, 2 * k + 1, l, mid),
               query(a, b, 2 * k + 2, mid, r));
  }
};
