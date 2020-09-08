# verify-helper: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum
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
    for i, v in enumerate(map(int, input().split())):
        graph.add_edge(i + 1, v, 1)
        graph.add_edge(v, i + 1, 1)
    hld = HeavyLightDecomposition(graph, 0, True)
    new_weights = [0] * N
    for i in range(N):
        new_weights[hld.vid[i]] = weights[i]
    rsq = SegmentTree.create_from_array(new_weights, operator.add, 0)

    ans = []
    for _ in range(Q):
        query = [int(x) for x in input().split()]
        if query[0] == 0:
            a, b = query[1:]
            rsq[hld.vid[a]] = rsq[hld.vid[a]] + b
        else:
            u = query[1]
            ans.append(rsq.query(hld.vid[u], hld.tail[u]))
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
