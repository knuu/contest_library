# verify-helper: PROBLEM https://judge.yosupo.jp/problem/lca
import sys

from python_library.graph.graph import Graph
from python_library.graph.heavy_light_decomposition import HeavyLightDecomposition

input = sys.stdin.buffer.readline


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
