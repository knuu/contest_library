from math import gcd


def lcm(arr):
    ret = 1
    for a in arr:
        ret = ret * a // gcd(ret, a)
    return ret
