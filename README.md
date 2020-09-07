# Library for Competitive Programming

[![Actions Status](https://github.com/knuu/contest_library/workflows/verify/badge.svg)](https://github.com/knuu/contest_library/actions)
[![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://knuu.github.io/contest_library/)

Library for Competitive Programming for C++, Python, Nim-lang

- Status
    - :heavy_check_mark:: implemented and verified by verification-helper
    - :warning:: implemented but not verified by verification-helper (but most of them are verified by at least one problem)
    - empty: not implemented yet

### Data Structrue

|                                         | C++       | Python              | Nim       |
| --------------------------------------- | --------- | ------------------- | --------- |
| Fenwick Tree (Point Add Range Sum)      | :warning: | :heavy_check_mark:  | :warning: |
| Matrix                                  | :warning: | :heavy_check_mark:  |           |
| k-D Tree                                | :warning: |                     |           |
| Range Tree                              | :warning: | :warning:           |           |
| Segment Tree (Point Update Range Query) | :warning: | :heavy_check_mark:  | :warning: |
| Union-Find                              | :warning: | :heavy_check_mark:  | :warning: |
| Weighted Union-Find                     |           | :heavy_check_mark:  |           |

- Notes
    - Range Tree of Python: only 2-dimensional

### Dynamic Programming

|                                | C++  | Python             | Nim  |
| ------------------------------ | ---- | ------------------ | ---- |
| Largest Rectangle in Histogram |      | :heavy_check_mark: |      |

### Graph

|                                                              | C++                | Python             | Nim       |
| ------------------------------------------------------------ | ------------------ | ------------------ | --------- |
| Shortest Path (Bellman-Ford)                                 | :warning:          | :warning:          |           |
| Shortest Path (Dijkstra)                                     | :warning:          | :warning:          |           |
| All Pairs Shortest Path (Floyd-Warshall)                     | :warning:          | :warning:          |           |
| Maximum Flow (Ford-Fulkerson)                                |                    | :warning:          |           |
| Maximum Flow (Dinic)                                         | :warning:          | :heavy_check_mark: |           |
| Minimum Cost Flow (Primal-Dual)                              | :warning:          | :heavy_check_mark: |           |
| Bipartite Matching                                           | :warning:          |                    |           |
| Minimum Spanning Tree (Prim)                                 | :warning:          | :warning:          |           |
| Minimum Spanning Tree (Kruskal)                              | :warning:          | :warning:          |           |
| Minimum Ratio Spanning Tree                                  | :warning:          |                    |           |
| Strongly Connected Componets                                 | :warning:          | :heavy_check_mark: | :warning: |
| Lowest Common Anscestor                                      | :heavy_check_mark: | :heavy_check_mark: |           |
| Heavy Light Decomposition <br/>(Centroid Path Decomposition) | :warning:          | :heavy_check_mark: |           |
| Maximum Independet Set                                       |                    | :heavy_check_mark: |           |
| Tree Diameter                                                |                    | :heavy_check_mark: |           |
| 2 Sat                                                        | :warning:          | :heavy_check_mark: |           |

- Notes
    - Bipartite Matching of C++: using Dinic
    - Lowest Common Anscestor
        - C++: using Doubling / Heavy Light Decomposition
        - Python: using Doubling

### Math

|                                           | C++       | Python             | Nim  |
| ----------------------------------------- | --------- | ------------------ | ---- |
| Discrete Logarithm (Baby-Step Giant-Step) |           | :heavy_check_mark: |      |
| Prime Factorization                       |           | :warning:          |      |
| Sieve of Eratosthenes                     | :warning: | :warning:          |      |
| Euler's Totient Function                  |           | :heavy_check_mark: |      |
| Extended Euclid Algorithm                 |           | :heavy_check_mark: |      |
| Linear Equation Solver                    |           | :warning:          |      |
| Linear Recursion Solver                   |           | :warning:          |      |
| K-th Root (Simple)                        |           | :heavy_check_mark: |      |

### String

|                         | C++       | Python             | Nim  |
| ----------------------- | --------- | ------------------ | ---- |
| Z-algorithm             |           | :heavy_check_mark: |      |
| Suffix Array (with LCP) | :warning: |                    |      |

### Geometry

|                            | C++  | Python             | Nim       |
| -------------------------- | ---- | ------------------ | --------- |
| Argument Sort              |      | :warning:          |           |
| ConvexHull (Graham's scan) |      | :heavy_check_mark: | :warning: |

## Author

knuu

## LICENSE

This library is released under the MIT License. However, when you use a part of this library for submitting to a judge server or the like for competition programming, you can omit the copyright notice and the permission notice.
