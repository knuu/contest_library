#define INF 1<<30

template <typename T>
struct AllPairsShortestPath {
  Graph<T> g;
  vector<vector<T>> dist;

  AllPairsShortestPath(const Graph<T> &g) : g(g) {
    dist.resize(g.V, vector<T>(g.V));
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) dist[i][j] = g.adj[i][j];
    }
  }

  void run() {
    for (int k = 0; k < g.V; k++) {
      for (int i = 0; i < g.V; i++) {
        for (int j = 0; j < g.V; j++) {
          if (dist[i][k] != INF and dist[k][j] != INF) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }
  }

  bool has_negative_loop() {
    for (int i = 0; i < g.V; i++) {
      if (dist[i][i] < 0) return true;
    }
    return false;
  }
};
