#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
// typedef tuple<int, int, int> T;
#define FOR(i, s, x) for (int i = s; i < (int)(x); i++)
#define REP(i, x) FOR(i, 0, x)
#define ALL(c) c.begin(), c.end()
#define DUMP(x) cerr << #x << " = " << (x) << endl
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

struct DisjointSet {
  std::vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

template <typename T>
struct Edge {
  int src, dst;
  T weight1, weight2;

  Edge(int src, int dst, T weight1, T weight2)
      : src(src), dst(dst), weight1(weight1), weight2(weight2) {}
};

template <typename T>
struct Graph {
  int V;
  std::vector<Edge<T>> E;

  Graph(int V) : V(V) {}

  void add_edge(int src, int dst, T weight1, T weight2) {
    E.emplace_back(src, dst, weight1, weight2);
  }
};

template <typename T>
struct MinimumRatioSpanningTree {
  Graph<T> g;
  std::vector<Edge<T>> mst;
  T mincost;

  MinimumRatioSpanningTree(const Graph<T> &g) : g(g) {}

  T run_mst(double &fcost, double &gcost) {
    fcost = gcost = 0;
    sort(g.E.begin(), g.E.end(), [&](Edge<T> e1, Edge<T> e2) {
      return e1.weight1 - mincost * e1.weight2 <
             e2.weight1 - mincost * e2.weight2;
    });
    DisjointSet uf(g.V);
    for (int i = 0, edge_count = g.V - 1; edge_count; i++) {
      Edge<T> e = g.E[i];
      if (!uf.same(e.src, e.dst)) {
        uf.unite(e.src, e.dst);
        mst.emplace_back(e);
        fcost += e.weight1;
        gcost += e.weight2;
        edge_count--;
      }
    }
    return fcost - mincost * gcost;
  }

  T run() {
    // Dinkelbach algorithm
    double fcost, gcost;
    for (mincost = 0.0;; mincost = fcost / gcost) {
      if (std::fabs(run_mst(fcost, gcost)) < 1e-8) {
        break;
      }
    }
    return mincost;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  Graph<double> g(N);
  REP(i, M) {
    int a, b;
    double c, t;
    cin >> a >> b >> c >> t;
    g.add_edge(a, b, c, t);
  }
  MinimumRatioSpanningTree<double> mrst(g);

  std::cout << std::fixed << std::setprecision(20) << mrst.run() << std::endl;
  return 0;
}
