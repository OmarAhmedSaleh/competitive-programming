/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int preOrder(TreeNode* currentNode , int maxSoFar){
    if(currentNode == nullptr){
      return 0;
    }
    int l = preOrder(currentNode->left , max(maxSoFar , currentNode->val));
    int r = preOrder(currentNode->right , max(maxSoFar , currentNode->val));
    return l + r + (currentNode->val >= maxSoFar ? 1 : 0);
  }
    int goodNodes(TreeNode* root) {
      const int oo = 2e9;
      return preOrder(root , -oo);
    }
};
