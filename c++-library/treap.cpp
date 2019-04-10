template <typename T>
struct Node {
  using type = T;
  T val;
  Node *left, *right;
  int priority;

  Node() {}
  Node(T val) : val(val), left(nullptr), right(nullptr) {}
  bool operator<(const Node<T> &n) const { return val < n.val; }
};

template <class Node>
struct Treap {
  using T = typename Node::type;
  Node *root, *nil;
  Treap();

  Node *find_last()

      bool add_node(T val) {
    Node *node = root, *parent = nil;
    while (node != nil) {
      if (val <= node->val) {
        node = node->left, parent = node;
      } else {
        node = node->right, parent = node;
      }
    }

    node = new Node(val);
    node->left = node->right = nil;
    if (parent == nil) {
      // treap が空の場合
      root = node;
    } else if (val <= parent->val) {
      parent->left = node;
    } else {
      parent->right = node;
    }
    return true;
  }
};

template <class Node>
Treap<Node>::Treap() : root(nullptr), nil(nullptr) {}