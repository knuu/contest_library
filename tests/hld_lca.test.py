# verify-helper: PROBLEM https://judge.yosupo.jp/problem/lca
# @import python_library/graph/graph.py
# @import python_library/graph/heavy_light_decomposition.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.graph.graph import Graph
from python_library.graph.heavy_light_decomposition import HeavyLightDecomposition


def main() -> None:
    N, Q = map(int, input().split())
    graph = Graph(N)
    for i, p in enumerate(map(int, input().split())):
        graph.add_edge(p, i + 1, 1)
    hld = HeavyLightDecomposition(graph)
    ans = [hld.lca(*map(int, input().split())) for _ in range(Q)]
    print(*ans, sep="\n")


if __name__ == "__main__":
    main()
