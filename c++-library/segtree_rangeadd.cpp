template <typename T>
struct RangeSumQuery {
  int N, _N;
  vector<T> data, datb;

  RangeSumQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N) N <<= 1;
    data.assign(2 * N - 1, 0);
    datb.assign(2 * N - 1, 0);
  }

  void add(int a, int b, T x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, T x, int k, int l, int r) {
    if (a <= l and r <= b) {
      data[k] += x;
    } else if (l < b and a < r) {
      datb[k] += (min(r, b) - max(l, a)) * x;
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
  }

  T sum(int a, int b) { return sum(a, b, 0, 0, N); }
  T sum(int a, int b, int k, int l, int r) {
    if (b <= l or r <= a) {
      return 0;
    } else if (a <= l and r <= b) {
      return data[k] * (r - l) + datb[k];
    } else {
      T res = data[k] * (min(r, b) - max(l, a));
      res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
      res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
      return res;
    }
  }
};
