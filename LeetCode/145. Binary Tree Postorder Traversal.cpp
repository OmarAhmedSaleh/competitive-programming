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
    vector<int> postorderTraversal(TreeNode* root) {
        vector < int > postOrder;
        vector < pair < TreeNode* , int > > seq;
        seq.push_back({root , 0});
        while((int)seq.size() > 0){
            pair < TreeNode* , int > p = seq.back();
            seq.pop_back();
            TreeNode * next;
            if(!p.first){
                continue;
            }
            if(p.second == 0){
                if(p.first->left){
                    p.second = 1;
                    next = p.first->left;
                    p.first->left = 0;
                    seq.push_back(p);
                    seq.push_back({next , 0});
                    continue;
                }else{
                    p.second = 1;
                }
            }
            if(p.second == 1){
                if(p.first->right){
                    next = p.first->right;
                    p.first->right = 0;
                    seq.push_back(p);
                    seq.push_back({next , 0});
                    continue;
                }else{
                    postOrder.push_back(p.first->val);
                }
            }
        }
        return postOrder;
    }
};
