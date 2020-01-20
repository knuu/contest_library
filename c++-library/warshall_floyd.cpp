#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// graph by adjacency matrix
template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<T>> adj;
  T inf;

  Graph(const int V, const T inf = std::numeric_limits<T>::max())
      : V(V), adj(V, std::vector<T>(V, inf)), inf(inf) {
    for (int i = 0; i < V; i++) adj[i][i] = 0;
  }

  void add_edge(const int src, const int dst, const T weight) {
    adj[src][dst] = weight;
  }
};

template <typename T>
struct AllPairsShortestPath {
  Graph<T> g;
  std::vector<std::vector<T>> dist;
  T inf;

  AllPairsShortestPath(const Graph<T> &g, T inf = std::numeric_limits<T>::max())
      : g(g), dist(g.V, std::vector<T>(g.V)), inf(inf) {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];
    }
  }

  void run() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
          if (dist[i][k] != inf and dist[k][j] != inf) {
            dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_loop() const {
    for (int i = 0; i < g.V; i++) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
  int V, E;
  std::cin >> V >> E;
  Graph<long long> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  AllPairsShortestPath<long long> apsp(g);
  apsp.run();
  if (apsp.has_negative_loop()) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
        if (apsp.dist[i][j] == apsp.inf) {
          std::cout << "INF" << (j == g.V - 1 ? '\n' : ' ');
        } else {
          std::cout << apsp.dist[i][j] << (j == g.V - 1 ? '\n' : ' ');
        }
      }
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  aoj();
  return 0;
}
