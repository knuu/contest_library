#define INF INT_MAX

template <typename T>
struct Node {
  int v; T dist;
  Node(int v, T dist) : v(v), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct ShortestPath {
  const Graph<T> g;
  vector<T> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void run(int start) {
    priority_queue<Node<T>> que;
    dist.assign(g.V, INF);
    dist[start] = 0;
    que.emplace(start, 0);
    prev[0] = -1;

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (dist[v] < cost) continue;
      for (Edge<T> e : g.E[v]) {
        if (dist[v] < dist[e.dst] - e.weight) {
          dist[e.dst] = dist[v] + e.weight;
          prev[e.dst] = v;
          que.emplace(e.dst, dist[e.dst]);
        }
      }
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
};
