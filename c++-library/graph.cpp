#include <vector>

// graph by adjacency list
template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(const int src, const int dst, const T weight)
      : src(src), dst(dst), weight(weight) {}
  Edge(const int dst, const T weight) : src(-1), dst(dst), weight(weight) {}
  Edge(const int dst) : src(-1), dst(dst), weight(T(1)) {}
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
