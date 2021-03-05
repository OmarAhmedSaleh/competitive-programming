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
    class levelInfo{
        public int numberOfNodes;
        public long totalValues;
        public levelInfo(){
            this.numberOfNodes = 0;
            this.totalValues = 0;
        }
        public void addNode(int val){
            this.totalValues += val;
            this.numberOfNodes++;
        }
        public Double avg(){
            return 1.0 * totalValues / numberOfNodes;
        }
    }
    private void dfs(TreeNode root, int level, ArrayList<levelInfo> treeInfo){
        if(root == null){return ;}
        if(level > treeInfo.size()){
            treeInfo.add(new levelInfo());
        }
        treeInfo.get(level - 1).addNode(root.val);
        dfs(root.left, level + 1, treeInfo);
        dfs(root.right, level + 1, treeInfo);
    }
    public List<Double> averageOfLevels(TreeNode root) {
        ArrayList<levelInfo> treeInfo = new ArrayList<levelInfo>();
        dfs(root, 1, treeInfo);
        List<Double> ans = new ArrayList<Double>();
        for(levelInfo level: treeInfo){
            ans.add(level.avg());
        }
        return ans;
    }
}
