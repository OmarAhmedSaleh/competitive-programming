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
  void preOrder(TreeNode* currentNode , vector < pair < int , int > > &children){
    if(currentNode == nullptr){
      return;
    }
    if(currentNode->left != nullptr){
      children[currentNode->val].first = currentNode->left->val;
      preOrder(currentNode->left , children);
    }
    if(currentNode->right != nullptr){
      children[currentNode->val].second = currentNode->right->val;
      preOrder(currentNode->right , children);
    }
    if(children[currentNode->val].first > children[currentNode->val].second){
      swap(children[currentNode->val].first , children[currentNode->val].second);
    }
  }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      vector < vector < pair < int , int > > > children(2 , vector < pair < int , int > > (100 , {-1 , -1}));
      if((root1 == nullptr && root2 != nullptr) || (root2 == nullptr && root1 != nullptr)){
        return false;
      }
      if(root1 == nullptr && root2 == nullptr){
        return true;
      }
      if(root1->val != root2->val){
        return false;
      }
      preOrder(root1 , children[0]);
      preOrder(root2 , children[1]);
      for(int i = 0;i < 100; i++){
        if(children[0][i].first != children[1][i].first || children[0][i].second != children[1][i].second){
          // cout << i << " " << children[0][i].first << " " << children[0][i].second << " " << children[1][i].first << " " << children[1][i].second << endl;
          return false;
        } 
      }
      
      return true;
    }
};
