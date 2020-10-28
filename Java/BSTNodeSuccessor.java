import java.util.PriorityQueue;
import java.util.Random;

public class Successor {
	public static void main(String[] args) {
		BSTNodeParent root = new BSTNodeParent(8);

		Random rand = new Random();
		for (int i = 0; i < 10; i++) {
			root.insert(rand.nextInt(16));
		}

		BSTNodeParent node = root.insert(6);

		printTree(root, 1);
		System.out.println("The parent to the node " + node.val + " is: " + solution1(node));
	}

	private static int solution1(BSTNodeParent node) {
		BSTNodeParent right = node.right;
		while (right != null && right.left != null) {
			right = right.left;
		}
		if (right == null) {
			return solution1(node.parent);
		}
		if (node.parent.left == node) {
			return Math.min(node.parent.val, right.val);
		}
		return right.val;
	}

	private static void printTree(BSTNodeParent root) {
		if (root == null) {
			return;
		}
		printTree(root.left);
		System.out.print(root.val + " ");
		printTree(root.right);
	}

	private static void printTree(BSTNodeParent n, int level) {
		if (n == null) {
			return;
		}
		printTree(n.left, level + 1);
		System.out.println("L" + level + ": " + n.val);
		printTree(n.right, level + 1);
	}
}

class BSTNodeParent {

	int val;
	BSTNodeParent parent;
	BSTNodeParent left;
	BSTNodeParent right;

	public BSTNodeParent(int val) {
		this.val = val;
		parent = null;
		left = null;
		right = null;
	}

	public BSTNodeParent insert(int v) {
		BSTNodeParent t = new BSTNodeParent(v);
		if (v < this.val) {
			if (left == null) {
				left = t;
				t.parent = this;
			} else {
				left.insert(v);
			}
		} else {
			if (right == null) {
				right = t;
				t.parent = this;
			} else {
				right.insert(v);
			}
		}
		return t;
	}
}
