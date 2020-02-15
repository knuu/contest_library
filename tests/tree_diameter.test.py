# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
# @import python-library/graph/tree_diameter.py


def aoj():
    N = int(input())
    graph = Graph(N)
    for _ in range(N-1):
        s, t, w = map(int, input().split())
        graph.add_edge(s, t, w)
        graph.add_edge(t, s, w)
    diam = TreeDiameter(graph)
    print(diam.run())


if __name__ == "__main__":
    aoj()
