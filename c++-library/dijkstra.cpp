#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  bool operator<(const Edge<T> &e) const { return weight > e.weight; }
};

template <typename T>
struct Graph {
  int V;
  std::vector<std::vector<Edge<T>>> E;
  Graph(const int V) : V(V) { E.resize(V); }
  void add_edge(const int src, const int dst, const T weight) {
    E[src].emplace_back(src, dst, weight);
  }
};

template <typename T>
struct Node {
  int v;
  T dist;
  Node(int v, T dist) : v(v), dist(dist){};
  bool operator<(const Node<T> &n) const {
    return dist > n.dist;  // reverse
  }
};

template <typename T>
struct ShortestPath {
  Graph<T> g;
  std::vector<T> dist;
  std::vector<int> prev;
  T inf;

  ShortestPath(const Graph<T> g, T inf = std::numeric_limits<T>::max())
      : g(g), dist(g.V), prev(g.V), inf(inf) {}

  void run(int start, int goal = -1) {
    std::priority_queue<Node<T>> que;
    std::fill(dist.begin(), dist.end(), inf);

    dist[start] = 0;
    que.emplace(start, 0);
    prev[0] = -1;

    while (!que.empty()) {
      Node<T> n = que.top();
      que.pop();
      int v = n.v;
      if (v == goal) return;
      T cost = n.dist;
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

  std::vector<int> build_path(int goal) {
    std::vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }
};

void aoj() {
  // https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A

  int V, E, r;
  std::cin >> V >> E >> r;
  Graph<int> g(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g.add_edge(s, t, d);
  }
  ShortestPath<int> sp(g);
  sp.run(r);
  for (int i = 0; i < g.V; i++) {
    if (sp.dist[i] == sp.inf) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << sp.dist[i] << std::endl;
    }
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  aoj();
  return 0;
}
