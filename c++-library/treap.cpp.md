---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
  bundledCode: "#line 1 \"c++-library/treap.cpp\"\ntemplate <typename T>\nstruct Node\
    \ {\n  using type = T;\n  T val;\n  Node *left, *right;\n  int priority;\n\n \
    \ Node() {}\n  Node(T val) : val(val), left(nullptr), right(nullptr) {}\n  bool\
    \ operator<(const Node<T> &n) const { return val < n.val; }\n};\n\ntemplate <class\
    \ Node>\nstruct Treap {\n  using T = typename Node::type;\n  Node *root, *nil;\n\
    \  Treap();\n\n  Node *find_last()\n\n      bool add_node(T val) {\n    Node *node\
    \ = root, *parent = nil;\n    while (node != nil) {\n      if (val <= node->val)\
    \ {\n        node = node->left, parent = node;\n      } else {\n        node =\
    \ node->right, parent = node;\n      }\n    }\n\n    node = new Node(val);\n \
    \   node->left = node->right = nil;\n    if (parent == nil) {\n      // treap\
    \ \u304C\u7A7A\u306E\u5834\u5408\n      root = node;\n    } else if (val <= parent->val)\
    \ {\n      parent->left = node;\n    } else {\n      parent->right = node;\n \
    \   }\n    return true;\n  }\n};\n\ntemplate <class Node>\nTreap<Node>::Treap()\
    \ : root(nullptr), nil(nullptr) {}\n"
  code: "template <typename T>\nstruct Node {\n  using type = T;\n  T val;\n  Node\
    \ *left, *right;\n  int priority;\n\n  Node() {}\n  Node(T val) : val(val), left(nullptr),\
    \ right(nullptr) {}\n  bool operator<(const Node<T> &n) const { return val < n.val;\
    \ }\n};\n\ntemplate <class Node>\nstruct Treap {\n  using T = typename Node::type;\n\
    \  Node *root, *nil;\n  Treap();\n\n  Node *find_last()\n\n      bool add_node(T\
    \ val) {\n    Node *node = root, *parent = nil;\n    while (node != nil) {\n \
    \     if (val <= node->val) {\n        node = node->left, parent = node;\n   \
    \   } else {\n        node = node->right, parent = node;\n      }\n    }\n\n \
    \   node = new Node(val);\n    node->left = node->right = nil;\n    if (parent\
    \ == nil) {\n      // treap \u304C\u7A7A\u306E\u5834\u5408\n      root = node;\n\
    \    } else if (val <= parent->val) {\n      parent->left = node;\n    } else\
    \ {\n      parent->right = node;\n    }\n    return true;\n  }\n};\n\ntemplate\
    \ <class Node>\nTreap<Node>::Treap() : root(nullptr), nil(nullptr) {}"
  dependsOn: []
  extendedDependsOn: []
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: false
  path: c++-library/treap.cpp
  requiredBy: []
  timestamp: '2019-04-11 03:52:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verificationStatusIcon: ':warning:'
  verifiedWith: []
documentation_of: c++-library/treap.cpp
layout: document
redirect_from:
- /library/c++-library/treap.cpp
- /library/c++-library/treap.cpp.html
title: c++-library/treap.cpp
---
