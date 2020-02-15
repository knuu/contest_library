#include <cmath>
#include <utility>
#include <vector>

struct LowestCommonAncestor {
  int V, log_V;
  std::vector<std::vector<int>> edge;

  std::vector<std::vector<int>> parent;
  std::vector<int> depth;

  LowestCommonAncestor(int V)
      : V(V),
        log_V(std::ceil(std::log2(V)) + 1),
        edge(V),
        parent(log_V),
        depth(V) {
    for (int i = 0; i < log_V; i++) parent[i].resize(V);
  }

  void add_edge(int a, int b) {
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  void dfs(int v, int par, int dep) {
    parent[0][v] = par;
    depth[v] = dep;
    for (auto child : edge[v]) {
      if (child != par) dfs(child, v, dep + 1);
    }
  }

  void build(int root = 0) {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < log_V; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        } else {
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }

  int run(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int k = 0; k < log_V; k++) {
      if ((depth[v] - depth[u]) >> k & 1) {
        v = parent[k][v];
      }
    }
    if (u == v) return u;

    for (int k = log_V - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }

  // cnt 個上の親を取得する
  int get_cntup_node(int v, int cnt) {
    if (cnt <= 0) return v;
    for (int k = log_V - 1; k >= 0; k--) {
      if (cnt >> k & 1) {
        v = parent[k][v];
      }
    }
    return v;
  }
};
