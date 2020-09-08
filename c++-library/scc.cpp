#include <algorithm>
#include <vector>

struct StronglyConnectedComponents {
  int V;
  std::vector<std::vector<int>> G, rG;
  std::vector<int> vs, cmp;
  std::vector<bool> used;

  StronglyConnectedComponents(const int V)
      : V(V), G(V), rG(V), cmp(V), used(V) {}

  void add_edge(const int from, const int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(const int v) {
    used[v] = true;
    for (int c : G[v])
      if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(const int v, const int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v])
      if (not used[c]) rdfs(c, k);
  }

  int run() {
    std::fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++)
      if (!used[v]) dfs(v);
    std::fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--)
      if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }

  std::vector<int> create_order() {
    std::vector<int> order(V);
    for (std::size_t i = 0; i < cmp.size(); i++) {
      order[cmp[i]] = i;
    }
    return order;
  }
};
