class FenwickTree:
    """FenwickTree (Binary Indexed Tree, 0-index)

    Queries:
        1. add(i, val): add val to i-th value
        2. sum(n): sum(bit[0] + ... + bit[n-1])

    complexity: O(log n)

    See: http://hos.ac/slides/20140319_bit.pdf
    """

    def __init__(self, a_list):
        self.N = len(a_list)
        self.bit = a_list[:]
        for _ in range(self.N, 1 << (self.N - 1).bit_length()):
            self.bit.append(0)
        for i in range(self.N - 1):
            self.bit[i | (i + 1)] += self.bit[i]

    def add(self, i, val):
        while i < self.N:
            self.bit[i] += val
            i |= i + 1

    def sum(self, n):
        ret = 0
        while n >= 0:
            ret += self.bit[n]
            n = (n & (n + 1)) - 1
        return ret

    def query(self, low, high):
        return self.sum(high) - self.sum(low)
