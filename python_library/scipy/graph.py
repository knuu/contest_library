import sys

import numpy as np
from scipy.optimize import linear_sum_assignment
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import (connected_components, dijkstra,
                                  floyd_warshall, maximum_bipartite_matching,
                                  maximum_flow, minimum_spanning_tree)

input = sys.stdin.readline


def create_graph(V: int, edges: np.array, dtype=None):
    """csr_matrix を作成する

    もし精度が足りない場合は dtype=object にする。
    """
    return csr_matrix((edges[:, 2], (edges[:, 0], edges[:, 1])),
                      shape=(V, V), dtype=dtype)


def calc_dist(graph: csr_matrix, start):
    return dijkstra(graph, indices=start)


def calc_min_span_tree(graph: csr_matrix):
    """return adj matrix of mst"""
    return minimum_spanning_tree(graph)


def calc_all_dist(graph: csr_matrix):
    return floyd_warshall(graph, directed=False)


def calc_scc(graph: csr_matrix):
    return connected_components(
        csgraph=graph, directed=True,
        connection="strong", return_labels=True)[1]


def calc_bipartite_matching(graph: csr_matrix) -> np.array:
    # かつ V1->V2 の枝が入った csr_matrix
    return maximum_bipartite_matching(graph, perm_type='column')


def yosupo_bi_match() -> None:
    # https://judge.yosupo.jp/problem/bipartitematching
    import scipy
    major, minor, _ = map(int, scipy.version.full_version.split('.'))
    if major < 1 or (major == 1 and minor < 4):
        raise RuntimeError
    L, R, M = map(int, input().split())
    sink, source = L+R, L+R+1
    in_, out = [], []
    edges = []
    for _ in range(M):
        a, b = map(int, input().split())
        in_.append(a)
        out.append(b + L)
        edges.append((a, b + L))
    for i in range(L):
        in_.append(source)
        out.append(i)
        edges.append((i, source))
    for i in range(R):
        in_.append(i + L)
        out.append(sink)
        edges.append((i + L, sink))
    edges.sort()
    graph = csr_matrix((np.ones(L+R+M, dtype=int), (in_, out)),
                       shape=(L+R+M, L+R+M))
    flow = maximum_flow(graph, source, sink)
    ans = []
    for (fr, to), val in zip(edges, flow.residual.data):
        if 0 <= fr < L and L <= to < L + R and val == 1:
            ans.append((fr, to - L))
    print(flow.flow_value)
    print("\n".join(f"{v1} {v2}" for v1, v2 in ans))


def yosupo_assign():
    # https://judge.yosupo.jp/problem/assignment
    N = int(input())
    mat = np.array(sys.stdin.read().split(), dtype=np.int64).reshape((N, N))
    row_ind, col_ind = linear_sum_assignment(mat)
    print(mat[row_ind, col_ind].sum())
    print(*col_ind)


if __name__ == '__main__':
    # yosupo_bi_match()
    yosupo_assign()
