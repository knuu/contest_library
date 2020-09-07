---
data:
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 64, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 84, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\n\nimport numpy as np\nfrom scipy.optimize import linear_sum_assignment\n\
    from scipy.sparse import csr_matrix\nfrom scipy.sparse.csgraph import (connected_components,\
    \ dijkstra,\n                                  floyd_warshall, maximum_bipartite_matching,\n\
    \                                  maximum_flow, minimum_spanning_tree)\n\ninput\
    \ = sys.stdin.readline\n\n\ndef create_graph(V: int, edges: np.array, dtype=None):\n\
    \    \"\"\"csr_matrix \u3092\u4F5C\u6210\u3059\u308B\n\n    \u3082\u3057\u7CBE\
    \u5EA6\u304C\u8DB3\u308A\u306A\u3044\u5834\u5408\u306F dtype=object \u306B\u3059\
    \u308B\u3002\n    \"\"\"\n    return csr_matrix((edges[:, 2], (edges[:, 0], edges[:,\
    \ 1])),\n                      shape=(V, V), dtype=dtype)\n\n\ndef calc_dist(graph:\
    \ csr_matrix, start):\n    return dijkstra(graph, indices=start)\n\n\ndef calc_min_span_tree(graph:\
    \ csr_matrix):\n    \"\"\"return adj matrix of mst\"\"\"\n    return minimum_spanning_tree(graph)\n\
    \n\ndef calc_all_dist(graph: csr_matrix):\n    return floyd_warshall(graph, directed=False)\n\
    \n\ndef calc_scc(graph: csr_matrix):\n    return connected_components(\n     \
    \   csgraph=graph, directed=True,\n        connection=\"strong\", return_labels=True)[1]\n\
    \n\ndef calc_bipartite_matching(graph: csr_matrix) -> np.array:\n    # \u304B\u3064\
    \ V1->V2 \u306E\u679D\u304C\u5165\u3063\u305F csr_matrix\n    return maximum_bipartite_matching(graph,\
    \ perm_type='column')\n\n\ndef yosupo_bi_match() -> None:\n    # https://judge.yosupo.jp/problem/bipartitematching\n\
    \    import scipy\n    major, minor, _ = map(int, scipy.version.full_version.split('.'))\n\
    \    if major < 1 or (major == 1 and minor < 4):\n        raise RuntimeError\n\
    \    L, R, M = map(int, input().split())\n    sink, source = L+R, L+R+1\n    in_,\
    \ out = [], []\n    edges = []\n    for _ in range(M):\n        a, b = map(int,\
    \ input().split())\n        in_.append(a)\n        out.append(b + L)\n       \
    \ edges.append((a, b + L))\n    for i in range(L):\n        in_.append(source)\n\
    \        out.append(i)\n        edges.append((i, source))\n    for i in range(R):\n\
    \        in_.append(i + L)\n        out.append(sink)\n        edges.append((i\
    \ + L, sink))\n    edges.sort()\n    graph = csr_matrix((np.ones(L+R+M, dtype=int),\
    \ (in_, out)),\n                       shape=(L+R+M, L+R+M))\n    flow = maximum_flow(graph,\
    \ source, sink)\n    ans = []\n    for (fr, to), val in zip(edges, flow.residual.data):\n\
    \        if 0 <= fr < L and L <= to < L + R and val == 1:\n            ans.append((fr,\
    \ to - L))\n    print(flow.flow_value)\n    print(\"\\n\".join(f\"{v1} {v2}\"\
    \ for v1, v2 in ans))\n\n\ndef yosupo_assign():\n    # https://judge.yosupo.jp/problem/assignment\n\
    \    N = int(input())\n    mat = np.array(sys.stdin.read().split(), dtype=np.int64).reshape((N,\
    \ N))\n    row_ind, col_ind = linear_sum_assignment(mat)\n    print(mat[row_ind,\
    \ col_ind].sum())\n    print(*col_ind)\n\n\nif __name__ == '__main__':\n    #\
    \ yosupo_bi_match()\n    yosupo_assign()\n"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: python_library/scipy/graph.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: python_library/scipy/graph.py
layout: document
redirect_from:
- /library/python_library/scipy/graph.py
- /library/python_library/scipy/graph.py.html
title: python_library/scipy/graph.py
---
