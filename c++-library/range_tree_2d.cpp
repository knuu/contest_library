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

template <typename T>
struct Point2D {
  T x, y;
  size_t idx;  // original index
  Point2D(T x, T y, size_t idx) : x(x), y(y), idx(idx) {}
  bool operator<(const Point2D<T> &other) const {
    return this->x < other.x or (this->x == other.x and this->y < other.y);
  }
};

template <typename T>
struct RangeTreeNode {
  T low, high;
  std::vector<T> assoc;
  std::vector<size_t> indices;
  RangeTreeNode(T inf = std::numeric_limits<T>::max())
      : low(inf), high(inf), assoc(), indices() {}
};

template <typename T>
struct RangeTree2D {
  size_t size_;
  std::vector<Point2D<T>> points;
  std::vector<RangeTreeNode<T>> nodes;
  T inf;
  RangeTree2D(T inf = std::numeric_limits<T>::max()) : inf(inf) {}

  void build(std::vector<Point2D<T>> points) {
    this->points = points;
    std::sort(this->points.begin(), this->points.end());
    this->size_ = 1;
    while (this->size_ < points.size()) {
      this->size_ <<= 1;
    }
    nodes.assign(2 * this->size_ - 1, RangeTreeNode<T>());
    for (size_t i = 0; i < this->points.size(); i++) {
      size_t idx = this->size_ - 1 + i;
      nodes[idx].low = nodes[idx].high = this->points[i].x;
      nodes[idx].assoc.emplace_back(this->points[i].y);
      nodes[idx].indices.emplace_back(this->points[i].idx);
    }
    for (int i = (int)this->size_ - 2; i >= 0; i--) {
      merge(nodes[2 * i + 1], nodes[2 * i + 2], nodes[i]);
    }
  }

  void merge(RangeTreeNode<T> &node1, RangeTreeNode<T> &node2,
             RangeTreeNode<T> &merged) {
    merged.low = std::min(node1.low, node2.low);
    merged.high = std::max(node1.high, node2.high);
    merged.assoc.resize(node1.assoc.size() + node2.assoc.size());
    merged.indices.resize(merged.assoc.size());

    node1.assoc.push_back(this->inf), node2.assoc.push_back(this->inf);
    for (size_t i = 0, l = 0, r = 0; i < merged.assoc.size(); i++) {
      if (node1.assoc[l] < node2.assoc[r] or
          (node1.assoc[l] == node2.assoc[r] and
           points[node1.indices[l]].x < points[node2.indices[r]].x)) {
        merged.assoc[i] = node1.assoc[l];
        merged.indices[i] = node1.indices[l];
        l++;
      } else {
        merged.assoc[i] = node2.assoc[r];
        merged.indices[i] = node2.indices[r];
        r++;
      }
    }
    node1.assoc.pop_back(), node2.assoc.pop_back();
  }

  void enumerate(T x_low, T x_high, T y_low, T y_high,
                 std::vector<size_t> &output, size_t idx = 0) const {
    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or
        nodes[idx].high < x_low) {
      return;
    } else if (x_low <= nodes[idx].low and nodes[idx].high <= x_high) {
      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),
                                   nodes[idx].assoc.end(), y_low) -
                  nodes[idx].assoc.begin();
      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),
                                   nodes[idx].assoc.end(), y_high + 1) -
                  nodes[idx].assoc.begin();
      for (size_t i = lb; i < ub; i++) {
        output.emplace_back(nodes[idx].indices[i]);
      }
      return;
    }
    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx + 1);
    enumerate(x_low, x_high, y_low, y_high, output, 2 * idx + 2);
  }

  int count(T x_low, T x_high, T y_low, T y_high, size_t idx = 0) const {
    if (idx >= 2 * size_ - 1 or x_high < nodes[idx].low or
        nodes[idx].high < x_low) {
      return 0;
    } else if (x_low <= nodes[idx].low and nodes[idx].high <= x_high) {
      size_t lb = std::lower_bound(nodes[idx].assoc.begin(),
                                   nodes[idx].assoc.end(), y_low) -
                  nodes[idx].assoc.begin();
      size_t ub = std::lower_bound(nodes[idx].assoc.begin(),
                                   nodes[idx].assoc.end(), y_high + 1) -
                  nodes[idx].assoc.begin();
      return ub - lb;
    }
    return count(x_low, x_high, y_low, y_high, 2 * idx + 1) +
           count(x_low, x_high, y_low, y_high, 2 * idx + 2);
  }
};

int main() {
  int N;
  scanf("%d", &N);
  std::vector<Point2D<int>> points;
  REP(i, N) {
    int x, y;
    scanf("%d %d", &x, &y);
    points.emplace_back(Point2D<int>(x, y, i));
  }
  RangeTree2D<int> rt2d;
  rt2d.build(points);
  int Q;
  scanf("%d", &Q);
  REP(i, Q) {
    int sx, tx, sy, ty;
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    std::vector<size_t> output;
    rt2d.enumerate(sx, tx, sy, ty, output);
    std::sort(output.begin(), output.end());
    for (size_t i : output) printf("%lu\n", i);
    printf("\n");
  }
  return 0;
}
