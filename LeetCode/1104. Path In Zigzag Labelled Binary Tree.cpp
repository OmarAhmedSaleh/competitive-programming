class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector < vector < int > > tree;
        int cur = 1;
        int level = 0;
        for(int i = 0 ; cur <= label && i < 22 ; i++){
            int sz = 1 << i;
            vector < int > v;
            while((int)v.size() < sz){
                v.push_back(cur);
                if(cur == label){
                    level = i;
                }
                cur++;
            }
            tree.push_back(v);
        }
        for(int i = 1 ;i <= level ; i += 2){
            reverse(tree[i].begin() , tree[i].end());
        }
        vector < int > ret;
        int idx = 0;
        for(int i = 0; i < (int)tree[level].size() ; i++){
            if(tree[level][i] == label){
                idx = i;
            }
        }
        while(level > -1){
            ret.push_back(tree[level][idx]);
            level--;
            idx /= 2;
        }
        reverse(ret.begin() , ret.end());
        return ret;
    }
};
