#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

template <typename T>
struct BipartiteMatching {
  struct Edge {
    int to, rev;
    T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) {}
  };

  typedef std::vector<Edge> Edges;
  std::vector<Edges> G;
  int V, source, sink;
  std::vector<int> level, iter;
  T inf;

  BipartiteMatching(const int V1, const int V2,
                    const T inf = std::numeric_limits<T>::max())
      : V(V1 + V2 + 2), inf(inf) {
    source = V - 2, sink = V - 1;
    G.resize(V);
    add_sink_source(V1, V2);
  }

  void add_edge(const int from, const int to) {
    G[from].emplace_back(to, G[to].size(), 1);
    G[to].emplace_back(from, static_cast<int>(G[from].size() - 1), 0);
  }

  void add_sink_source(const int V1, const int V2) {
    for (int i = 0; i < V1; i++) add_edge(source, i);
    for (int i = V1; i < V1 + V2; i++) add_edge(i, sink);
  }

  void bfs(const int source) {
    level.assign(V, -1);
    std::queue<int> que;
    que.emplace(source);
    level[source] = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (int i = 0; i < (int)G[v].size(); i++) {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.emplace(e.to);
        }
      }
    }
  }

  T dfs(const int v, const int sink, const T flow) {
    if (v == sink) return flow;
    for (int &i = iter[v]; i < static_cast<int>(G[v].size()); i++) {
      Edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        T d = dfs(e.to, sink, std::min(e.cap, flow));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  T run() {
    T flow = 0;
    while (true) {
      bfs(source);
      if (level[sink] < 0) return flow;
      iter.assign(V, 0);
      T f;
      while ((f = dfs(source, sink, inf)) > 0) {
        flow += f;
      }
    }
  }
};

void yosupo_bm() {
  // https://judge.yosupo.jp/problem/bipartitematching
  int L, R, M;
  std::cin >> L >> R >> M;
  BipartiteMatching<int> bm(L, R);
  for (int i = 0; i < M; i++) {
    int a, b;
    std::cin >> a >> b;
    bm.add_edge(a, b + L);
  }
  std::cout << bm.run() << '\n';
  for (int i = 0; i < L; i++) {
    for (auto e : bm.G[i]) {
      if (e.cap == 0 and e.to < L + R) {
        std::cout << i << ' ' << e.to - L << '\n';
      }
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  yosupo_bm();
  return 0;
}