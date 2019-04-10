import bisect

class RangeTreeNode:
    def __init__(self, inf = 10**10):
        self._inf = inf
        self.range_ = (inf, inf)
        self.indices = []
        self.assoc = []

    @classmethod
    def merge(cls, node1, node2, data):
        merged_node = cls()
        merged_node.range_ = (min(node1.range_[0], node2.range_[0]),
                              max(node1.range_[1], node2.range_[1]))
        sentinel = node1._inf
        node1.assoc.append(sentinel)
        node2.assoc.append(sentinel)
        i = j = 0
        while min(node1.assoc[i], node2.assoc[j]) < sentinel:
            if node1.assoc[i] < node2.assoc[j] or \
               (node1.assoc[i] == node2.assoc[j] and \
                data[node1.indices[i]][0] < data[node2.indices[j]][0]):
                merged_node.assoc.append(node1.assoc[i])
                merged_node.indices.append(node1.indices[i])
                i += 1
            else:
                merged_node.assoc.append(node2.assoc[j])
                merged_node.indices.append(node2.indices[j])
                j += 1
        node1.assoc.pop()
        node2.assoc.pop()
        return merged_node

class RangeTree2D:
    def __init__(self, inf = 10**10):
        self._inf = inf

    def build(self, points):
        points = sorted([(x, y, i) for i, (x, y) in enumerate(points)])
        self._size = 1
        while self._size < len(points):
            self._size <<= 1
        self._data = [RangeTreeNode() for _ in range(self._size * 2 - 1)]
        for i, (x, y, idx) in enumerate(points):
            self._data[self._size - 1 + i].range_ = (x, x)
            self._data[self._size - 1 + i].indices.append(idx)
            self._data[self._size - 1 + i].assoc.append(y)
        for i in reversed(range(self._size - 1)):
            self._data[i] = RangeTreeNode.merge(self._data[2 * i + 1], self._data[2 * i + 2], points)

    def query(self, range_x, range_y, output, idx=0):
        if idx >= 2 * self._size - 1:
            return
        elif range_x[0] <= self._data[idx].range_[0] and self._data[idx].range_[1] <= range_x[1]:
            low = bisect.bisect_left(self._data[idx].assoc, range_y[0])
            high = bisect.bisect_left(self._data[idx].assoc, range_y[1] + 1)

            for i in range(low, high):
                output.append(self._data[idx].indices[i])
            return
        else:
            self.query(range_x, range_y, output, 2 * idx + 1)
            self.query(range_x, range_y, output, 2 * idx + 2)

if __name__ == '__main__':
    N = int(input())
    points = [tuple(map(int, input().split())) for _ in range(N)]
    rt = RangeTree2D()
    rt.build(points)
    for _ in range(int(input())):
        x1, x2, y1, y2 = map(int, input().split())
        output = []
        rt.query((x1, x2), (y1, y2), output)
        if output:
            output.sort()
            print(*output, sep='\n')
        print()
