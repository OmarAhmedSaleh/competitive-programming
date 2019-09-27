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
  vector < int > seq , sum;
  bool flag = false;
  int n = 0;
  void dfs(TreeNode* curNode){
    if(!flag){
      seq.push_back(curNode->val);  
    }
    if(flag){
      int idx = (lower_bound(seq.begin() , seq.end() , curNode->val) - seq.begin());
      curNode->val = sum[n - 1];
      if(idx > 0){
        curNode->val -= sum[idx - 1];
      }
    }
    if(curNode->right){
     dfs(curNode->right);
    }
    if(curNode->left){
      dfs(curNode->left);
    }
  }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
      if((int)seq.size() > 0){
        sort(seq.begin() , seq.end());  
      }
      sum = seq;
      for(int i = 1;i < (int)sum.size(); i++){
        sum[i] += sum[i - 1];
      }
      flag = true;
      n = (int)seq.size();
      dfs(root);
      return root;
    }
};
