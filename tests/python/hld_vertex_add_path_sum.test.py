# verify-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_path_sum
import operator
import sys

from python_library.data_structures.segment_tree import SegmentTree
from python_library.graph.graph import Graph
from python_library.graph.heavy_light_decomposition import \
    HeavyLightDecomposition

input = sys.stdin.buffer.readline


def main() -> None:
    N, Q = map(int, input().split())
    weights = [int(x) for x in input().split()]
    graph = Graph(N)
    for _ in range(N - 1):
        u, v = map(int, input().split())
        graph.add_edge(u, v, 1)
        graph.add_edge(v, u, 1)
    hld = HeavyLightDecomposition(graph)
    new_weights = [0] * N
    for i in range(N):
        new_weights[hld.vid[i]] = weights[i]
    rsq = SegmentTree.create_from_array(new_weights, operator.add, 0)

    ans = []
    for _ in range(Q):
        t, a, b = map(int, input().split())
        if t == 0:
            rsq[hld.vid[a]] = rsq[hld.vid[a]] + b
        else:
            ans.append(hld.query_path(a, b, 0, rsq.query, operator.add))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
