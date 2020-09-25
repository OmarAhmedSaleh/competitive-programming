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
    const TreeNode * nullNode = nullptr;
    const int MAX_NUMBER_OF_NODES = 8500;
    const string EMPTY_STR = "";
    
    inline bool isLeaf(TreeNode *root){
        return root->right == nullNode && root->left == nullNode;
    }
    inline char convertIntToChar(int let){
        assert(let >= 0 && let <= 25);
        return (char) let + 'a';
    }
    void dfs(TreeNode *currentNode, string &minSoFar, string path){
        if(currentNode == nullptr){
            return ;
        }
        path += convertIntToChar(currentNode->val);
        if(isLeaf(currentNode)){
            reverse(path.begin(), path.end());
            if(minSoFar > path || minSoFar == EMPTY_STR){
                minSoFar = path;
            }
        } else{
            dfs(currentNode->left, minSoFar, path);
            dfs(currentNode->right, minSoFar, path);
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallest = "";
        dfs(root, smallest, "");
        return smallest;
    }
};
