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
    public void dfs(TreeNode root, int v, int currentDepth, int targetDepth){
        if(root == null){return ;}
        if(currentDepth + 1 == targetDepth){
            root.left = new TreeNode(v, root.left, null);
            root.right = new TreeNode(v, null, root.right);
            return;
        }
        dfs(root.left, v, currentDepth + 1, targetDepth);
        dfs(root.right, v, currentDepth + 1, targetDepth);
        
    }
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        // handle if d == 1 
        if(d == 1){
            return new TreeNode(v, root, null);
        }
        dfs(root, v, 1, d);
        return root;
    }
}
