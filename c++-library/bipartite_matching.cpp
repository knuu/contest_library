#define INF 1 << 29

template <typename T>
struct BipartiteMatching {
  struct Edge {
    int to, rev;
    T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) {}
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V, source, sink;
  vector<int> level, iter;

  BipartiteMatching(int V1, int V2) {
    V = V1 + V2 + 2, source = V - 2, sink = V - 1;
    G.resize(V);
    add_sink_source(V1, V2);
  }

  void add_edge(int from, int to) {
    G[from].emplace_back(to, G[to].size(), 1);
    G[to].emplace_back(from, (int)G[from].size() - 1, 0);
  }

  void add_sink_source(int V1, int V2) {
    for (int i = 0; i < V1; i++) add_edge(source, i);
    for (int i = V1; i < V1 + V2; i++) add_edge(i, sink);
  }

  void bfs(int source) {
    level.assign(V, -1);
    queue<int> que;
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

  T dfs(int v, int sink, T flow) {
    if (v == sink) return flow;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
      Edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        T d = dfs(e.to, sink, min(e.cap, flow));
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
      while ((f = dfs(source, sink, INF)) > 0) {
        flow += f;
      }
    }
  }
};
