class Solution {
public:
    int minSteps(int n) {
      const int oo = 1e9;
        vector < int > dp(n + 1, oo);
      dp[0] = dp[1] = 0;
      for(int i = 1; i < n ; i++){
        int cur = i;
        int steps = 1;
        while(cur <= n){
          dp[cur] = min(dp[cur] , dp[i] + steps);
          // paste
          cur += i;
          steps++;
        }
      }
      return dp[n];
    }
};
