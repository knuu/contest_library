import sys
import ctypes


def popcount(N):
    if sys.platform.startswith('linux'):
        libc = ctypes.cdll.LoadLibrary('libc.so.6')
        return libc.__sched_cpucount(ctypes.sizeof(ctypes.c_long), (ctypes.c_long * 1)(N))
    elif sys.platform == 'darwin':
        libc = ctypes.cdll.LoadLibrary('libSystem.dylib')
        return libc.__popcountdi2(N)
    else:
        assert(False)


def maximum_independet_set(v: int, bad: int, adj_mat):
    """最大独立集合
    v: 今調べている頂点
    bad: 使わないと決めた頂点 (bit)
    adj_mat: 隣接行列 (bit のリスト)

    最大独立集合のサイズと最大独立集合を返す
    """
    if v == len(adj_mat):
        return 0, 0

    ret, ret_set = 0, 0

    deg = popcount(adj_mat[v] & ~bad)

    # use v
    if (bad >> v & 1) == 0:
        new_bad = bad | (1 << v) | (adj_mat[v] & ~bad)
        cand, cand_set = maximum_independet_set(v+1, new_bad, adj_mat)
        if cand + 1 > ret:
            ret, ret_set = cand + 1, cand_set | (1 << v)

    # do not use v
    if deg > 1 or (bad >> v & 1):
        new_bad = bad
        if (bad >> v & 1) == 0:
            new_bad |= (1 << v)
        cand, cand_set = maximum_independet_set(v+1, new_bad, adj_mat)
        if cand > ret:
            ret, ret_set = cand, cand_set

    return ret, ret_set


def yosupo():
    # https://judge.yosupo.jp/problem/maximum_independent_set
    N, M = map(int, input().split())
    adj_mat = [0] * N
    for _ in range(M):
        u, v = map(int, input().split())
        adj_mat[u] |= 1 << v
        adj_mat[v] |= 1 << u
    size, mis = maximum_independet_set(0, 0, adj_mat)
    print(size)
    print(*[i for i in range(N) if mis >> i & 1])


if __name__ == "__main__":
    yosupo()
