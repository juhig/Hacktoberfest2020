class BinaryTreeNode {
  BinaryTreeNode left;
  BinaryTreeNode right;
  String data;

  BinaryTreeNode(this.data);

  add(BinaryTreeNode node) {
    if (node > this) {
      if (this.right == null) this.right = node;
      else this.right.add(node);
    } else {
      if (this.left == null) this.left = node;
      else this.left.add(node);
    }
  }

  operator > (BinaryTreeNode node) {
    return int.parse(this.data) > int.parse(node.data);
  }

  Iterable<String> ascending() sync* {
    if (this.left != null) yield* this.left.ascending();
    yield this.data;
    if (this.right != null) yield* this.right.ascending();
  }
}

class BinarySearchTree {
  BinaryTreeNode root;
  BinarySearchTree(String value) {
    this.root = new BinaryTreeNode(value);
  }

  insert(String data) => this.root.add(new BinaryTreeNode(data));

  get sortedData => this.root.ascending().toList();
}

main() {
  final bst = new BinarySearchTree('4')..insert('2')..insert("6")..insert("1")..insert("3")..insert("5")..insert("7");

  print(bst.sortedData);
}