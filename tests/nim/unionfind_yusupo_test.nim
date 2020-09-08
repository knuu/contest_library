# verify-helper: PROBLEM https://judge.yosupo.jp/problem/unionfind

include "nim-library/utils.nim"
include "nim-library/union_find.nim"

when isMainModule:
  let (N, Q) = input(int, 2)
  var dset = initUnionFindTree(N)
  for i in 0..<Q:
    let (t, u, v) = input(int, 2)
    if t == 0:
      dset.uniteNode(u, v)
    else:
      echo dset.hasSameRoot(u, v).int
