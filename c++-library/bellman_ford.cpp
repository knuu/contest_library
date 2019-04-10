#define INF 1<<30

template <typename T>
struct ShortestPath {
  const Graph<T> g;
  vector<T> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void run(int start) {
    dist.assign(g.V, INF);
    dist[start] = 0;
    prev[start] = -1;
    while (true) {
      bool update = false;
      for (int i = 0; i < g.V; i++) {
        for (Edge<T> e : g.E[i]) {
          if (dist[i] != INF && dist[i] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[i] + e.weight;
            prev[e.dst] = i;
            update = true;
          }
        }
      }
      if (!update) break;
    }
  }

  vector<int> build_path(int goal) {
    vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
  }

  bool find_negative_loop(int start) {
    dist.assign(g.V, INF);
    dist[start] = 0;
    for (int i = 0; i < g.V; i++) {
      for (int j = 0; j < g.V; j++) {
        for (Edge<T> e : g.E[j]) {
          if (dist[j] != INF && dist[j] + e.weight < dist[e.dst]) {
            dist[e.dst] = dist[j] + e.weight;
            if (i == g.V - 1) return true;
          }
        }
      }
    }
    return false;
  }
};
