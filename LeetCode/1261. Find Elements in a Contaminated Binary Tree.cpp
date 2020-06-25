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
class FindElements {
public:
  unordered_map < int , bool > allValues;
  void recover(TreeNode* currentNode){
    if(currentNode == nullptr){
      return ;
    }
    allValues[currentNode->val] = true;
    if(currentNode->left != nullptr){
      currentNode->left->val = currentNode->val * 2 + 1;
      recover(currentNode->left);
    }
    if(currentNode->right != nullptr){
      currentNode->right->val = currentNode->val * 2 + 2;
      recover(currentNode->right);
    }
  }
    FindElements(TreeNode* root) {
      if(root != nullptr){
        root->val = 0;
      }
      recover(root);
    }
    
    bool find(int target) {
        return allValues.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
