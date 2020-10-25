class Solution {
public:
    vector<pair<int,int>>cnt;
    int memo[600][101][101];
    int solve(int idx,int ones,int zeros, int sz){
        if(ones < 0 || zeros < 0){
            return -2*sz;
        }
        if(idx == sz){
            return 0;
        }
        if(memo[idx][ones][zeros] != -1){return memo[idx][ones][zeros];}
        int ans = max(solve(idx + 1, ones, zeros, sz), solve(idx + 1, ones - cnt[idx].first, zeros - cnt[idx].second,sz) + 1);
        return memo[idx][ones][zeros] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        if((int)strs.size() == 0){
            return 0;
        }
        memset(memo, -1,sizeof(memo));
        cnt.resize((int)strs.size(),{0,0});
        for(int i = 0;i < (int)strs.size();i++){
            for(auto c: strs[i]){
                cnt[i].first += c == '1' ? 1 : 0;
                cnt[i].second += c == '0' ? 1 : 0;
            }
        }
        return solve(0,n,m, (int)strs.size());
    }
};
