type
  SegTree[T] = object
    dat: seq[T]
    size: Natural
    real_size: Natural
    merge: proc (x, y: T): T
    default: T

proc max_merge[T](x, y: T): T =
  result = if x > y: x else: y

proc min_merge[T](x, y: T): T =
  result = if x > y: y else: x

proc sum_merge[T](x, y: T): T = x + y

proc initSegTree[T](size: Natural, merge: proc (x, y: T): T = max_merge, default = 0): SegTree[T] =
  var real_size = 1
  while real_size < size: real_size = real_size shl 1
  return SegTree[T](
    dat: newSeqWith(2 * real_size - 1, default),
    size: size,
    real_size: real_size,
    merge: merge,
    default: default
  )

proc update[T](segt: var Segtree[T], k: Natural, val: T) =
  assert(k < segt.size)
  var key = k + segt.real_size - 1
  segt.dat[key] = val
  while key > 0:
    key = (key - 1) div 2
    segt.dat[key] = segt.merge(segt.dat[2 * key + 1], segt.dat[2 * key + 2])

proc query[T](segt: var SegTree[T], a, b, k, left, right: Natural): T =
  if right <= a or b <= left: return segt.default
  if a <= left and right <= b: return segt.dat[k]
  let mid = (left + right) div 2
  return segt.merge(segt.query(a, b, 2 * k + 1, left, mid),
                   segt.query(a, b, 2 * k + 2, mid, right))

proc query[T](segt: var SegTree[T], a, b: Natural): T =
  return segt.query(a, b, 0, 0, segt.real_size)
