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
  const char LEFT = '0';
  const char RIGHT = '1';
  void DFS(TreeNode* currentNode , string currentPath , string &actualPath , TreeNode *targetPointer){
    if(currentNode == nullptr){
      return;
    }
    if(currentNode == targetPointer){
      actualPath = currentPath;
      return;
    }
    DFS(currentNode->left , currentPath + LEFT , actualPath , targetPointer);
    DFS(currentNode->right, currentPath + RIGHT , actualPath , targetPointer);
  }
  TreeNode* getPtr(TreeNode *root , string path){
    int sz = (int)path.size();
    TreeNode *currentNode = root;
    for(int i = 0;i < sz ;i++){
      if(path[i] == LEFT){
        currentNode = currentNode->left;
      }else{
        currentNode = currentNode->right;
      }
    }
    return currentNode;
  }
 
  TreeNode* ifNotUniqueVal(TreeNode* original, TreeNode* cloned, TreeNode* target){
    // special Case original root == target
      if(original == target){
        return cloned;
      }
      string path = "";
      DFS(original , "" , path , target);
      if(path != ""){
        return getPtr(cloned , path);
      }
      return nullptr;
  }
   void getPtrByNodeVal(TreeNode* oNode , TreeNode* cNode , TreeNode* target , TreeNode * &ans){
    if(oNode == nullptr){
      return;
    }
    if(target->val == oNode->val){
      ans = cNode;
      return;
    }
    getPtrByNodeVal(oNode->left , cNode->left , target , ans);
    getPtrByNodeVal(oNode->right , cNode->right , target , ans);
    
  }
    TreeNode* UniqueVal(TreeNode* original, TreeNode* cloned, TreeNode* target){
      TreeNode* ans = nullptr;
      getPtrByNodeVal(original , cloned , target , ans);
      return ans;
  }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      return UniqueVal(original , cloned , target);
    }
};
