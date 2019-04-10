import sequtils

type
  FenwickTree[T] = object
    dat: seq[T]
    size: Natural
    initial: T

proc initFenwickTree[T](size: Natural, initial: T): FenwickTree[T] =
  return FenwickTree[T](dat: newSeqWith(size, initial), size: size, initial: initial)

proc update[T](fwt: var FenwickTree[T], k: Natural, val: T) =
  assert(k < fwt.size)
  var key = k
  while key < fwt.size:
    fwt.dat[key] += val
    key = key or (key + 1)

proc query[T](fwt: var FenwickTree[T], k: int): T =
  assert(k >= 0)
  var key = k - 1
  result = fwt.initial
  while key >= 0:
    result += fwt.dat[key]
    key = (key and (key + 1)) - 1

proc query[T](fwt: var FenwickTree[T], left, right: Natural): T =
  assert(left <= right and right <= fwt.size)
  return fwt.query(right) - fwt.query(left)

proc index[T](fwt: var FenwickTree[T], k: Natural): T =
  assert(k < fwt.size)
  return fwt.query(k + 1) - fwt.index(k)
