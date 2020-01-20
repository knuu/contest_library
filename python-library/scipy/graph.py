import numpy as np
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import dijkstra


def create_graph(V: int, edges: np.array, dtype=None):
    """csr_matrix を作成する

    もし精度が足りない場合は dtype=object にする。
    """
    return csr_matrix((edges[:, 2], (edges[:, 0], edges[:, 1])),
                      shape=(V, V), dtype=dtype)


def calc_dist(graph: csr_matrix, start):
    return dijkstra(graph, indices=start)
