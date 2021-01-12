class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length];
        for(int i = 0;i < nums.length;i++){
            dp[i] = nums[i];
            if(i - 2 > -1){
                dp[i] = dp[i - 2] + nums[i];
            }
            if(i - 1 > -1){
                dp[i] = Math.max(dp[i], dp[i - 1]);
            }
        }
        return nums.length > 0 ? dp[nums.length - 1]: 0;
    }
}
