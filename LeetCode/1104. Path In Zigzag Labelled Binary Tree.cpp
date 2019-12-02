class Solution {
public:
    int rev_row(int level , int cur){
            int start = 1 << (level);
            int dif = cur - start;
            int end = (1 << (level + 1)) - 1;
        return end - dif;
    }
    vector<int> pathInZigZagTree(int label) {
        vector < int > ret;
        if(label == 1){
            return {1};
        }
        int level = log2(label);
        int cur = label;
        ret.push_back(label);
        if(level & 1 ){
            cur = rev_row(level , cur);
        }
        while(level > 0){
            int p = cur / 2;
            int pp = p;
            if(level % 2 == 0){
                pp = rev_row(level - 1 , p);
            }
            level--;
            ret.push_back(pp);
            cur = p;
        }
        reverse(ret.begin() , ret.end());
        return ret;
    }
};
