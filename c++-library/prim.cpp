template <typename T>
struct Node {
  int v, src; T dist;
  Node(int v, int src, T dist) : v(v), src(src), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct MinimumSpanningTree {
  Graph<T> g;
  vector<Node<T>> mst;
  int mincost;

  MinimumSpanningTree(const Graph<T> &g) : g(g) { }

  int run() {
    mincost = 0;

    vector<bool> used(g.V, false);

    priority_queue<Node<T>> que;
    que.emplace(0, -1, 0);

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (used[v]) continue;
      if (n.src != -1) mst.push_back(n);
      used[v] = true;
      mincost += cost;
      for (Edge<T> e : g.E[v]) {
        if (!used[e.dst]) que.emplace(e.dst, v, e.weight);
      }
    }
    return mincost;
  }
};
