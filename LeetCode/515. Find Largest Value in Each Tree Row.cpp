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
  void preOrder(TreeNode* currentNode , vector < int > &maxValues , int depth){
    if(currentNode == nullptr){
      return ;
    }
    if(depth > (int)maxValues.size()){
      maxValues.push_back(currentNode->val);
    }
    int index = depth - 1;
    maxValues[index] = max(maxValues[index] , currentNode->val);
    preOrder(currentNode->left , maxValues , depth + 1);
    preOrder(currentNode->right , maxValues , depth + 1);
  }
    vector<int> largestValues(TreeNode* root) {
      vector < int > maxValues;
      preOrder(root , maxValues , 1);
      return maxValues;
    }
};
