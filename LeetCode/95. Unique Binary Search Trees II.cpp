// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    void insert(TreeNode* root, int val){
        if(root == nullptr){
            return;
        }
        if(root->val > val){
            insert(root->left, val);
            if(root->left == nullptr){
                root->left = new TreeNode(val);
            }
        }else{
            insert(root->right, val);
            if(root->right == nullptr){
                root->right = new TreeNode(val);
            }
        }
    }
    bool areIdentical(TreeNode* tree1, TreeNode* tree2){
        if(tree1 == nullptr || tree2 == nullptr){
            return tree1 == nullptr && tree2 == nullptr;
        }
        return tree1->val == tree2->val && areIdentical(tree1->left, tree2->left) && areIdentical(tree1->right, tree2->right) ;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector < int > perm;
        for(int i = 0;i < n ;i++){
            perm.push_back(i + 1);
        }
        vector < TreeNode*> trees;
        if(n == 0){return trees;}
        do{
            TreeNode* tree = new TreeNode(perm[0]);
            for(int i = 1 ; i < n ; i++){
                insert(tree, perm[i]);
            }
            trees.push_back(tree);
        }while(next_permutation(perm.begin(), perm.end()));
        
        for(int i = 0;i < (int)trees.size() ; i++){
        for(int j = i + 1;j < (int)trees.size() ;j++){
            if(areIdentical(trees[i], trees[j])){
                swap(trees[j], trees.back());
                j--;
                trees.pop_back();
            }
        }
    }
        return trees;
    }
    
};
