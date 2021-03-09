/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    private List<Integer> inOrder;
    private int itr;
    private void inOrderTraversal(TreeNode root, List<Integer> order){
        if(root == null){return;}
        inOrderTraversal(root.left, order);
        order.add(root.val);
        inOrderTraversal(root.right, order);
    }
    public BSTIterator(TreeNode root) {
        itr = 0;
        inOrder = new ArrayList<Integer>();
        this.inOrderTraversal(root, inOrder);
    }
    
    public int next() {
        return inOrder.get(itr++);
        
    }
    
    public boolean hasNext() {
        return itr < inOrder.size();
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
