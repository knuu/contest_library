from math import gcd


def lcm(arr):
    ret = 1
    for a in arr:
        ret = ret * a // gcd(ret, a)
    return ret


def aoj():
    N = int(input())
    print(lcm([int(x) for x in input().split()]))


if __name__ == '__main__':
    aoj()
