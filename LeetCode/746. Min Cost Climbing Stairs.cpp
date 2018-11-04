class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = (int)cost.size();
        vector<int> dp(sz+1,2e9);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 0 ; i < sz ; i++){
            for(int jump = 1 ; jump < 3 ; jump++){
                int dis = i + jump;
                if(dis <= sz ){
                    dp[dis] = min(dp[dis] , dp[i] + cost[i]);
                }
            }
        }
        return dp[sz];
    }
};
