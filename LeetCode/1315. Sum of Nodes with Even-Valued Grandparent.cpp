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
  void DFS(TreeNode* currentNode , bool evenG , bool evenP , int &sum){
    if(currentNode == nullptr){
      return ;
    }
    if(evenG){
      sum += currentNode->val;
    }
    DFS(currentNode->left , evenP , currentNode->val % 2 == 0 , sum);
    DFS(currentNode->right , evenP , currentNode->val % 2 == 0, sum);
  }
    int sumEvenGrandparent(TreeNode* root) {
      int sum = 0;
      DFS(root , 0 , 0 , sum);
      return sum;
    }
};
