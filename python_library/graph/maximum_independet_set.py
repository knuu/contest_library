from python_library.misc.popcount import popcount


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
        cand, cand_set = maximum_independet_set(v + 1, new_bad, adj_mat)
        if cand + 1 > ret:
            ret, ret_set = cand + 1, cand_set | (1 << v)

    # do not use v
    if deg > 1 or (bad >> v & 1):
        new_bad = bad
        if (bad >> v & 1) == 0:
            new_bad |= 1 << v
        cand, cand_set = maximum_independet_set(v + 1, new_bad, adj_mat)
        if cand > ret:
            ret, ret_set = cand, cand_set

    return ret, ret_set
