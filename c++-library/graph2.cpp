#define INF 1<<30

// graph by adjacency matrix

template <typename T>
struct Graph {
  int V;
  vector<vector<T>> adj;

  Graph(int V) : V(V) {
    adj.resize(V, vector<T>(V, INF));
    for (int i = 0; i < V; i++) adj[i][i] = 0;
  }

  void add_edge(int src, int dst, T weight) {
    adj[src][dst] = weight;
  }

};
