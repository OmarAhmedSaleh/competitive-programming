class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        for(int i = 0;i <= amount; i++){
            dp[i] = -1;
        }
        // base case
        dp[0] = 0;
        for(int coin: coins){
            if(coin > amount){continue;}
            dp[coin] = 1;
        }
        for(int i = 1;i <= amount ;i++){
            for(int coin: coins){
                int j = i - coin;
                if(j < 0 || dp[j] == -1){continue;}
                dp[i] = dp[i] == -1 ? dp[j] + 1 : Math.min(dp[i], dp[j] + 1); 
            }
        }
        return dp[amount]; 
    }
}
