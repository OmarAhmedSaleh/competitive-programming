// https://www.hackerrank.com/challenges/is-binary-search-tree/problem?isFullScreen=false

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    pair<int,int> dfs(Node *root, bool &isBST){
        pair<int,int> l = {root->data , root->data};
        pair<int,int> r = {root->data , root->data};
        if(root->left != nullptr){
            l = dfs(root->left, isBST);
            isBST &= l.second < root->data;
        }
        if(root->right != nullptr){
            r = dfs(root->right, isBST);
            isBST &= r.first > root->data;
        }
        int mn = min(l.first, min(r.first, root->data));
        int mx = max(l.second, max(r.second, root->data));
        return {mn, mx};
    }
	bool checkBST(Node* root) {
        bool isBST = true;
        if(root != nullptr){
            dfs(root, isBST);
        }
        return isBST;
	}
