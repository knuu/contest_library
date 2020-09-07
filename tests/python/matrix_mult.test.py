# verify-helper: PROBLEM http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_D
# @import python_library/data_structures/matrix.py
import sys

sys.path.insert(0, ".")
input = sys.stdin.buffer.readline

from python_library.data_structures.matrix import Matrix


def main() -> None:
    N, M, _ = map(int, input().split())
    mat1, mat2 = [], []
    for _ in range(N):
        mat1.append([int(x) for x in input().split()])
    for _ in range(M):
        mat2.append([int(x) for x in input().split()])
    A, B = Matrix(mat1, False), Matrix(mat2, False)
    for row in (A @ B).mat:
        print(*row)


if __name__ == "__main__":
    main()
