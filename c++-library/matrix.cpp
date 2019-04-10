#include <vector>
#include <cassert>

using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;

mat mul(const mat &a, const mat &b) {
  int N = a.size(), M = b.size(), S = a[0].size();
  assert(S == (int)b.size());
  mat c(N, vec(M));
  for (int i = 0; i < N; i++) {
    for (int k = 0; k < S; k++) {
      for (int j = 0; j < M; j++) {
	c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

mat pow(mat a, long long b) {
  int N = a.size();
  mat c(N, vec(N));
  for (int i = 0; i < N; i++) c[i][i] = 1;
  while (b > 0) {
    if (b & 1) c = mul(c, a);
    a = mul(a, a);
    b >>= 1;
  }
  return c;
}
