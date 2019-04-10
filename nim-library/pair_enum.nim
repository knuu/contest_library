# import sequtils, strutils, strscans, algorithm, math, future, sets, queues, tables # for yukicoder (0.17.1)
import sequtils, strutils, algorithm, math, future, sets, queues, tables # for AtCoder (0.13.0)
template getLine: string = stdin.readLine
template getInteger: int = getLine.parseInt
template getBiggestInteger: int64 = getLine.parseBiggestInt
template getIntSeq: seq[int] = getLine.split.map(parseInt)
template getBigIntSeq: seq[int64] = getLine.split.map(parseBiggestInt)

proc dfs(num_array: seq[int], left, right, center, rest: var seq[int]): void =
  if rest.len == 0:
    assert(left.len == right.len)
    if num_array.len mod 2 == 1:
      assert(center.len == 1)

    let generated_pairs = left.zip(right).mapIt((num_array[it[0]], num_array[it[1]]))
    generated_pairs.echo
  elif center.len == 0 and num_array.len mod 2 == 1:
    center.add(rest.pop)
    dfs(num_array, left, right, center, rest)
    for i in 0..<rest.len:
      swap(center[0], rest[i])
      dfs(num_array, left, right, center, rest)
      swap(center[0], rest[i])
    rest.add(center.pop)
  else:
    left.add(rest.pop)
    right.add(rest.pop)
    dfs(num_array, left, right, center, rest)
    for i in 0..<rest.len:
      swap(right[^1], rest[i])
      dfs(num_array, left, right, center, rest)
      swap(right[^1], rest[i])
    rest.add(right.pop)
    rest.add(left.pop)

proc pair_enumeration(num_array: seq[int]): void =
  var
    left, right, center = newSeq[int]()
    rest = toSeq(0..<num_array.len)
  dfs(num_array, left, right, center, rest)

when isMainModule:
  pair_enumeration(@[1, 2, 3, 4])
  echo()
  pair_enumeration(@[1, 2, 3, 4, 5])
