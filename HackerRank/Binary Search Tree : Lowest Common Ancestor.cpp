// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void dfs(Node *current, vector<Node*> path, vector<vector<Node*>> &pathes, int v1,int v2){
        if(current == nullptr){return;}
        path.push_back(current);        
        if(current->data == v1 || current->data == v2){
            pathes.push_back(path);
        }
        dfs(current->left, path, pathes, v1, v2);
        dfs(current->right, path, pathes, v1, v2);
    }
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        vector<Node*>path;
        vector<vector<Node*>>pathes;
        dfs(root, path, pathes, v1, v2);
        for(int i = (int)pathes[0].size() - 1;i > -1;i--){
            for(int j = 0;j < (int)pathes[1].size();j++){
                if(pathes[0][i]->data == pathes[1][j]->data){
                    return pathes[0][i];
                }
            }
        }
        return root;
    }

}; //End of Solution
