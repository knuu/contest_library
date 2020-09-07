#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<int> maximum_clique_naive(
    const std::vector<int> &vs, const std::vector<std::vector<int>> &adj_mat) {
  assert(vs.size() < 31);
  std::vector<int> adj_bits(vs.size());
  for (size_t i = 0; i < vs.size(); i++) {
    for (size_t j = i + 1; j < vs.size(); j++) {
      if (adj_mat[vs[i]][vs[j]]) {
        adj_bits[i] |= 1 << j;
        adj_bits[j] |= 1 << i;
      }
    }
  }

  size_t ans_bit = 0, ans_count = 0;
  for (size_t bit = 0; bit < (1U << vs.size()); bit++) {
    bool flag = true;
    size_t bit_count = __builtin_popcount(bit);
    for (size_t i = 0; i < vs.size(); i++) {
      if ((bit >> i & 1) and
          __builtin_popcount(adj_bits[i] & bit) + 1U != bit_count) {
        flag = false;
        break;
      }
    }
    if (flag and bit_count > ans_count) {
      ans_bit = bit;
      ans_count = bit_count;
    }
  }

  std::vector<int> ret;
  for (size_t i = 0; i < vs.size(); i++) {
    if (ans_bit >> i & 1) ret.emplace_back(vs[i]);
  }
  return ret;
}

void abc002_d() {
  int N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int>> adj_mat(N, std::vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    adj_mat[x][y] = adj_mat[y][x] = 1;
  }
  std::vector<int> vs(N);
  std::iota(vs.begin(), vs.end(), 0);
  std::cout << maximum_clique_naive(vs, adj_mat).size() << std::endl;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  abc002_d();
  return 0;
}