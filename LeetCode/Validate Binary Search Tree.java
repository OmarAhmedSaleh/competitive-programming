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
    class subTreeValues{
        int l, r;
        boolean notBST;
        subTreeValues(int val){
            l = r = val;
            notBST = false;
        }
        public int minVal(){
            return l < r ? l : r;
        }
        public int maxVal(){
            return l > r ? l : r;
        }
    }
    public void pull(subTreeValues ret, subTreeValues subTree, TreeNode root){
            ret.l = Math.min(ret.l, subTree.minVal());
            ret.r = Math.max(ret.r, subTree.maxVal());
            ret.notBST |= subTree.notBST;
    }
    public subTreeValues dfs(TreeNode root){
        if(root == null){
            return new subTreeValues(-1);
        }
        subTreeValues ret = new subTreeValues(root.val);
        
        if(root.left != null){
            subTreeValues leftSubTree = dfs(root.left);
            if(leftSubTree.r >= root.val || leftSubTree.l >= root.val){ret.notBST = true;}
            pull(ret,leftSubTree,root);
        }
        if(root.right != null){
            subTreeValues rightSubTree = dfs(root.right);
            if(rightSubTree.r <= root.val || rightSubTree.l <= root.val){ret.notBST = true;}
            pull(ret,rightSubTree,root);

        }
        return ret;
    }
    public boolean isValidBST(TreeNode root) {
        if(root == null){return false;}
        subTreeValues rootValues = dfs(root);
        return !rootValues.notBST;
        
    }
}
