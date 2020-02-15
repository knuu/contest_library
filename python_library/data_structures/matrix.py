from copy import deepcopy


class Matrix:
    ZERO = 0
    ONE = 1

    def __init__(self, mat, copy: bool = True):
        assert len(mat) and len(mat[0])
        if copy:
            self.mat = deepcopy(mat)
        else:
            self.mat = mat

    def __matmul__(self, other):
        ret = [[self.ZERO] * len(other.mat[0]) for _ in range(len(self.mat))]
        for i in range(len(self.mat)):
            for k in range(len(self.mat[0])):
                for j in range(len(other.mat[0])):
                    ret[i][j] += self.mat[i][k] * other.mat[k][j]
        return Matrix(ret)

    def __pow__(self, k):
        ret = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])
        for i in range(len(self.mat)):
            ret.mat[i][i] = self.ONE
        n = Matrix(deepcopy(self.mat))

        while k:
            if k & 1:
                ret = ret.__matmul__(n)
            n = n.__matmul__(n)
            k >>= 1
        return ret

    @property
    def shape(self):
        return len(self.mat), len(self.mat[0])

    def __str__(self):
        return "[{}]\n".format("\n".join(str(row) for row in self.mat))


def det(mat: Matrix, mod: int = 998244353) -> int:
    # mat は変更されることに注意。
    ret = 1
    N = mat.shape[0]
    for i in range(N):
        pivot = i
        for j in range(i + 1, N):
            if abs(mat.mat[j][i]) > abs(mat.mat[pivot][i]):
                pivot = j
        mat.mat[i], mat.mat[pivot] = mat.mat[pivot], mat.mat[i]
        ret *= mat.mat[i][i] * (-1 if i != pivot else 1)
        ret %= mod
        if not mat.mat[i][i]:
            break
        inv = pow(mat.mat[i][i], mod - 2, mod)
        for j in range(i + 1, N):
            for k in reversed(range(i, N)):
                mat.mat[j][k] += mod - mat.mat[i][k] * mat.mat[j][i] % mod * inv % mod
                mat.mat[j][k] %= mod
    return ret
