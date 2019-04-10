def givens(A, b):
    """ solve linear equation
        cf. http://www.slideshare.net/tmaehara/ss-18244588
        complexity: O(n^3)
        used in kupc2012_C
    """
    def mkrot(x, y):
        r = pow(x**2+y**2, 0.5)
        return x/r, y/r

    def rot(x, y, c, s):
        return c*x+s*y, -s*x+c*y

    n = len(b)
    for i in range(n):
        for j in range(i+1, n):
            c, s = mkrot(A[i][i], A[j][i])
            b[i], b[j] = rot(b[i], b[j], c, s)
            for k in range(i, n):
                A[i][k], A[j][k] = rot(A[i][k], A[j][k], c, s)
    for i in reversed(range(n)):
        for j in range(i+1, n):
            b[i] -= A[i][j] * b[j]
        b[i] /= A[i][i]
    return b
