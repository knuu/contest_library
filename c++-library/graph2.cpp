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
