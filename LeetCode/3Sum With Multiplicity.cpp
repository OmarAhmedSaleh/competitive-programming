class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int ans = 0;
        const int MOD = 1000000007, MAX = 101;
        vector<vector<int>> cnt((int)arr.size(), vector<int>(MAX,0));
        for(int i = (int)arr.size() - 2; i > - 1; i--){
            cnt[i] = cnt[i + 1];
            cnt[i][arr[i + 1]]++;
        }
        for(int i = 0;i < (int)arr.size();i++){
            for(int j = i + 1; j < (int)arr.size();j++){
                int rem = target - (arr[i] + arr[j]);
                if(rem < 0 || rem > 100){continue;}
                ans += cnt[j][rem];
                if(ans >= MOD){ans -= MOD;}
            }
        }
        return ans;
    }
};
