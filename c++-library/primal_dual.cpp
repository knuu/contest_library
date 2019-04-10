const int INF = 1e7;

template <typename T>
struct MinCostFlow {
  struct Edge {
    int to, rev; T cap, cost;
    Edge(int to, int rev, T cap, T cost) : to(to), rev(rev), cap(cap), cost(cost) { }
  };

  struct Node {
    int v; T dist;
    Node(int v, T dist) : v(v), dist(dist) { };
    bool operator < (const Node &n) const {
      return dist > n.dist; // reverse
    }
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V;
  vector<int> dist, h, prevv, preve;

  MinCostFlow(int V) : V(V) { G.resize(V); }

  void add_edge(int from, int to, T cap, T cost) {
    G[from].emplace_back(to, G[to].size(), cap, cost);
    G[to].emplace_back(from, (int)G[from].size()-1, 0, -cost);
  }

  T run(int source, int sink, T f) {
    T res = 0;
    h.resize(V, 0);
    prevv.resize(V), preve.resize(V);
    while (f > 0) {
      priority_queue<Node> pque;
      dist.assign(V, INF);
      dist[source] = 0;
      pque.emplace(source, 0);
      while (not pque.empty()) {
        Node n = pque.top(); pque.pop();
        int v = n.v; T cost = n.dist;
        if (dist[v] < cost) continue;
        for (int i = 0; i < (int)G[v].size(); i++) {
          Edge e = G[v][i];
          if (e.cap > 0 and dist[v] - h[e.to] < dist[e.to] - e.cost - h[v]) {
            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
            prevv[e.to] = v, preve[e.to] = i;
            pque.emplace(e.to, dist[e.to]);
          }
        }
      }
      if (dist[sink] == INF) return -1;
      for (int v = 0; v < V; v++) h[v] += dist[v];

      T d = f;
      for (int v = sink; v != source; v = prevv[v]) {
        d = min(d, G[prevv[v]][preve[v]].cap);
      }
      f -= d;
      res += d * h[sink];
      for (int v = sink; v != source; v = prevv[v]) {
        Edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
};
