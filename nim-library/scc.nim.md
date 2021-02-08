---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: nim
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://nim-lang.org/docs/manual.html#macros-expression-macros
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import algorithm, complex, future, macros, math, queues, rationals, sets,\
    \ sequtils, strutils, tables # for 0.13.0\n# import algorithm, bitops, complex,\
    \ deques, heapqueue, lenientops, macros, math, queues, rationals, sets, sequtils,\
    \ strformat, strscans, strutils, sugar, tables # for 0.19\n\n# ----- input macro\
    \ by nimon -----\n\nmacro unpack*(input: seq; count: static[int]): untyped =\n\
    \  result = quote do: ()\n  when NimMinor <= 13:\n    for i in 0..<count: result[0].add\
    \ quote do: `input`[`i`]\n  else:\n    for i in 0..<count: result.add quote do:\
    \ `input`[`i`]\n\n## count == 0 \u306E\u3068\u304D unpack\u3057\u306A\u3044(seq)\n\
    ## count >  0 \u306E\u3068\u304D count\u500B\u5206 unpack \u3057\u305F\u7D50\u679C\
    \u306E tuple \u3092\u8FD4\u3059\ntype UnselectableTypeError = object of Exception\n\
    template input*(typ: typedesc; count: Natural = 0): untyped =\n  let line = stdin.readLine.split\n\
    \  when count == 0:\n    when typ is int:    line.map(parseInt)\n    elif typ\
    \ is float:  line.map(parseFloat)\n    elif typ is string: line\n    else: raise\
    \ newException(UnselectableTypeError, \"You selected a type other than int, float\
    \ or string\")\n  else:\n    when typ is int:    line.map(parseInt).unpack(count)\n\
    \    elif typ is float:  line.map(parseFloat).unpack(count)\n    elif typ is string:\
    \ line.unpack(count)\n    else: raise newException(UnselectableTypeError, \"You\
    \ selected a type other than int, float or string\")\n\n# 2-dim table\ntemplate\
    \ inputs*(typ: typedesc; count = 0; rows = 1): untyped =\n  (1..rows).mapIt(input(typ,\
    \ count))\n\n# ----- end input macro -----\n\n# from https://nim-lang.org/docs/manual.html#macros-expression-macros\n\
    # when NimMinor >= 16, you can use future.dump (sugar.dump)\nmacro debug(args:\
    \ varargs[untyped]): untyped =\n  result = nnkStmtList.newTree()\n  for n in args:\n\
    \    result.add newCall(\"write\", newIdentNode(\"stderr\"), newLit(n.repr))\n\
    \    result.add newCall(\"write\", newIdentNode(\"stderr\"), newLit(\": \"))\n\
    \    result.add newCall(\"write\", newIdentNode(\"stderr\"), n)\n    result.add\
    \ newCall(\"writeLine\", newIdentNode(\"stderr\"), newLit(\"\"))\n\nconst MOD\
    \ = 10^9 + 7\nconst INF = high(int)\n\ntype\n  StronglyConnectedComponents = object\n\
    \    graph, rev_graph: seq[seq[int]]\n    vs, comp, sorted_vs: seq[int]\n    used:\
    \ seq[bool]\n\nproc initSCC(size: Natural): StronglyConnectedComponents =\n  return\
    \ StronglyConnectedComponents(\n    graph: newSeqWith(size, newSeq[int]()),\n\
    \    rev_graph: newSeqWith(size, newSeq[int]()),\n    vs: newSeq[int](),\n   \
    \ comp: newSeq[int](size),\n    sorted_vs: newSeq[int](size),\n    used: newSeq[bool](size)\n\
    \  )\n\nproc add_edge(scc: var StronglyConnectedComponents, v1: int, v2: int)\
    \ =\n  scc.graph[v1].add(v2)\n  scc.rev_graph[v2].add(v1)\n\nproc dfs(scc: var\
    \ StronglyConnectedComponents, v: int) =\n  scc.used[v] = true\n  for c in scc.graph[v]:\n\
    \    if not scc.used[c]:\n      scc.dfs(c)\n  scc.vs.add(v)\n\nproc rev_dfs(scc:\
    \ var StronglyConnectedComponents, v: int, k: int) =\n  scc.used[v] = true\n \
    \ scc.comp[v] = k\n  for c in scc.rev_graph[v]:\n    if (not scc.used[c]):\n \
    \     scc.rev_dfs(c, k)\n\nproc run(scc: var StronglyConnectedComponents): int\
    \ =\n  scc.used.fill(false)\n  for v in 0..<scc.graph.len:\n    if not scc.used[v]:\n\
    \      scc.dfs(v)\n  scc.used.fill(false)\n  var k = 0\n  for v in scc.vs.reversed:\n\
    \    if not scc.used[v]:\n      scc.rev_dfs(v, k)\n      k.inc\n  for i, v in\
    \ scc.comp:\n    scc.sorted_vs[v] = i\n  return k\n\nwhen isMainModule:\n  let\n\
    \    (N, M) = input(int, 2)\n  var scc = initSCC(N)\n  for i in 0..<(N - 1 + M):\n\
    \    let (a, b) = input(int, 2)\n    scc.add_edge(a, b)\n  scc.run()\n  debug(scc.sorted_vs)\n"
  dependsOn: []
  isVerificationFile: false
  path: nim-library/scc.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nim-library/scc.nim
layout: document
redirect_from:
- /library/nim-library/scc.nim
- /library/nim-library/scc.nim.html
title: nim-library/scc.nim
---
