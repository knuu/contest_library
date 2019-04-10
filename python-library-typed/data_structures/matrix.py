from copy import deepcopy
from typing import List, TypeVar, Generic

T = TypeVar('T', int, float, complex)


class Matrix(Generic[T]):
    def __init__(self, mat: List[List[T]], ZERO: T = 0, ONE: T = 1) -> None:
        assert(len(mat) and len(mat[0]))
        self.ZERO: T = ZERO
        self.ONE: T = ONE
        self.mat: List[List[T]] = deepcopy(mat)

    def __mult__(self, other: 'Matrix') -> 'Matrix':
        ret: List[List[T]] = [[self.ZERO] * len(other.mat[0]) for _ in range(len(self.mat))]
        for i in range(len(self.mat)):
            for j in range(len(self.mat[0])):
                for k in range(len(self.mat[0])):
                    ret[i][j] += self.mat[i][k] * other.mat[k][j]
        return Matrix(ret)

    def __pow__(self, k: int) -> 'Matrix':
        ret: 'Matrix' = Matrix([[self.ZERO] * len(self.mat[0]) for _ in range(len(self.mat))])
        for i in range(len(self.mat)):
            ret.mat[i][i] = self.ONE
        n: 'Matrix' = Matrix(deepcopy(self.mat))

        while k:
            if k & 1:
                ret = ret.__mult__(n)
            n = n.__mult__(n)
            k >>= 1
        return ret

    def __str__(self) -> str:
        return '[{}]\n'.format('\n'.join(str(row) for row in self.mat))
