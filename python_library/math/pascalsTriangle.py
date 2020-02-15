from copy import deepcopy


def pascalsTriangle(n):
    assert n >= 0
    psTri = [[0]*n for _ in range(n)]
    for i in range(n):
        psTri[i][0] = 1
        psTri[i][i] = 1
        for j in range(1, i):
            psTri[i][j] = psTri[i-1][j-1] + psTri[i-1][j]
    return deepcopy(psTri)
