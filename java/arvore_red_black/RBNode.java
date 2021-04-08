package arvore_red_black;

public class RBNode<T> {
	public static final boolean RED = false;
	public static final boolean BLACK = true;
	public boolean color;
	private T item;
	private RBNode<T> parent;
	private RBNode<T> left;
	private RBNode<T> right;

	public RBNode() {
		color = BLACK;
		item = null;
		parent = null;
		left = null;
		right = null;
	}

	public RBNode(T item) {
		this.item = item;
		color = BLACK;
		parent = null;
		left = null;
		right = null;
	}

	@Override
	public String toString() {
		return "RBNode: [item=" + item + ", color=" + ((!color) ? "Red" : "Black") + ", parent=" + parent + ", left=" + left + ", right=" + right + "]";
	}
}
