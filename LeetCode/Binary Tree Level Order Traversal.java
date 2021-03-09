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
class Solution {
    public void dfs(TreeNode root, int depth, List<List<Integer>> order){
        if(root == null){return;}
        if(order.size() < depth){
            order.add(new ArrayList<Integer> ());
        }
        order.get(depth - 1).add(root.val);
        dfs(root.left, depth + 1, order);
        dfs(root.right, depth + 1, order);
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> order = new ArrayList<List<Integer>> ();
        dfs(root, 1, order);
        return order;
    }
}
