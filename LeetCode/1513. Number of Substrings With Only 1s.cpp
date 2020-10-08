class Solution {
public:
    int numSub(string s) {
        const int MOD = 1000000007;
        s += '0';
        int sz = (int)s.size(), len = 0 , ans = 0;
        for(int i = 0;i < sz ; i++){
            if(s[i] == '1'){
                len++;
            }else{
                ans = (1LL * ans + 1LL * ( 1LL * len * (len + 1)) / 2) % MOD;
                len = 0;
            }
        }
        return ans;
    }
};
