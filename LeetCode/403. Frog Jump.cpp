class Solution {
public:
    int memo[1100][1101];
    int solve(int idx, int k, vector<int> &s){
        if(k < 1){return 0;}
        if(idx >= (int)s.size() - 1){return 1;}
        if(memo[idx][k] != -1){return memo[idx][k];}
        int can = 0;
        for(int j = -1; !can && j < 2; j++){
            int pos = lower_bound(s.begin(), s.end(), s[idx] + k + j) - s.begin();
            if(pos < (int)s.size() && s[pos] == s[idx] + k + j){
                can |= solve(pos, k + j, s);
            }
        }
        return memo[idx][k] = can;
    }
    bool canCross(vector<int>& stones) {
        if(stones.size() > 1 && stones[1] != 1){
            return false;
        }
        memset(memo, -1, sizeof(memo));
        return solve(1, 1, stones);
    }
};
