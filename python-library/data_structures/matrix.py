from copy import deepcopy


class Matrix:
    ZERO = 0
    ONE = 1

    def __init__(self, mat):
        assert(len(mat) and len(mat[0]))
        self.mat = deepcopy(mat)

    def __mult__(self, other):
        ret = [[self.ZERO] * len(other.mat[0]) for _ in range(len(self.mat))]
        for i in range(len(self.mat)):
            for j in range(len(self.mat[0])):
                for k in range(len(self.mat[0])):
                    ret[i][j] += self.mat[i][k] * other.mat[k][j]
        return Matrix(ret)

    def __pow__(self, k):
        ret = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])
        for i in range(len(self.mat)):
            ret.mat[i][i] = self.ONE
        n = Matrix(deepcopy(self.mat))

        while k:
            if k & 1:
                ret = ret.__mult__(n)
            n = n.__mult__(n)
            k >>= 1
        return ret

    def __str__(self):
        return '[{}]\n'.format('\n'.join(str(row) for row in self.mat))
