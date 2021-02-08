---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: nim
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/nim.py\"\
    , line 86, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# tuple \u306A\u3069 C++ \u3067\u76F4\u63A5\u5BFE\u5FDC\u3059\u308B\u3082\
    \u306E\u304C\u306A\u3044\u3068\u4F7F\u3048\u306A\u3044\ntype\n  CPriorityQueue\
    \ {.importcpp: \"std::priority_queue\", header: \"<queue>\".} [T] = object\nproc\
    \ cNewPriorityQueue(T: typedesc): CPriorityQueue[T]\n  {.importcpp: \"std::priority_queue<'*1>()\"\
    , nodecl.}\nproc newPriorityQueue*[T](): CPriorityQueue[T] = cNewPriorityQueue(T)\n\
    proc len*[T](this: CPriorityQueue[T]): int {.importcpp: \"#.size(@)\", nodecl.}\n\
    proc add*[T](this: CPriorityQueue[T], x: T) {.importcpp: \"#.push(@)\", nodecl.}\n\
    proc top*[T](this: CPriorityQueue[T]): T {.importcpp: \"#.top(@)\", nodecl.}\n\
    proc pop*[T](this: CPriorityQueue[T]) {.importcpp: \"#.pop(@)\", nodecl.}\n"
  dependsOn: []
  isVerificationFile: false
  path: nim-library/priority_queue.nim
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nim-library/priority_queue.nim
layout: document
redirect_from:
- /library/nim-library/priority_queue.nim
- /library/nim-library/priority_queue.nim.html
title: nim-library/priority_queue.nim
---
