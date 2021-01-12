class Solution {
    int[][] memo;
    int[] coins;
    public int solve(int idx, int amount){
        if(amount == 0){return 0;}
        if(idx == coins.length){return (int)1e9;}
        if(memo[idx][amount] != -1){return memo[idx][amount];}
        int ans = solve(idx + 1, amount);
        for(int i = 0;i <= amount; i++){
            if(i * coins[idx] > amount){break;}
            ans = Math.min(ans, solve(idx + 1, amount - i * coins[idx]) + i);
        }
        return memo[idx][amount] = ans;
    }
    public int coinChange(int[] coins, int amount) {
        memo = new int[coins.length][amount + 1];
        this.coins = coins;
        for(int i = 0;i < coins.length; i++){
            for(int j = 0;j <= amount; j++){
                memo[i][j] = -1;
            }
        }
        Arrays.sort(this.coins);
        return solve(0, amount) != 1e9 ? solve(0, amount) : -1;
    }
}
