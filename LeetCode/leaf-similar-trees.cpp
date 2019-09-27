/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector < int > seq[2];
  int idx = 0;
  void dfs(TreeNode* curNode){
    if(curNode->left){
      dfs(curNode->left);
    }
    if(curNode->right){
      dfs(curNode->right);
    }
    if(!curNode->left && !curNode->right){
      seq[idx].push_back(curNode->val);
    }
  }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      dfs(root1);
      idx = 1;
      dfs(root2);
      if(seq[0].size() != seq[1].size()){
        return false;
      }
      int sz = (int)seq[0].size();
      for(int i = 0;i < sz ; i++){
        if(seq[0][i] != seq[1][i]){
          return false;
        }
      }
      return true;
    }
};
