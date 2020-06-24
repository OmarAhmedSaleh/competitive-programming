class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int k) {
      int n = (int)A.size();
      const double OO = 1e18;
      vector < vector < double > > dp(n , vector < double > (k + 1 , -OO));
      // base case when the remaining partitions = 1
      int sum = 0;
      for(int i = 0;i < n ; i++){
        sum += A[i];
        dp[i][1] = 1.0 * sum / (i + 1);
      }
      for(int partition = 2; partition <= k ; partition++){
        for(int i = 0;i < n ;i++){
          sum = 0;
          for(int len = 1; len <= i; len++){
            int st = i - len + 1;
            sum += A[st];
            double prev = 0;
            if(st > 0){prev = dp[st - 1][partition - 1];}
            dp[i][partition] = max(dp[i][partition] , (1.0 * sum / len) + prev);
          }
       }  
      }
      double best = -OO;
      for(int i = 1; i <= k; i++){
        best = max(best , dp[n - 1][i]);
      }
      return best;
    }
};
