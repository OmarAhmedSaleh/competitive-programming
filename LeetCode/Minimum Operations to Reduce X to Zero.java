class Solution {
    public int minOperations(int[] nums, int x) {
        int n = nums.length;
        long[] prefix = new long[n];
        long[] suffix = new long[n];
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        int ans = n + 1;
        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i - 1] + nums[i];
        }
        for(int i = n - 2;i > -1;i--){
            suffix[i] = suffix[i + 1] + nums[i];
        }
        for(int i = 0;i < n; i++){
            if(prefix[i] == x){
                ans = Math.min(ans, i + 1);
            }
        }
        for(int i = n - 1; i > -1; i--){
            if(suffix[i] == x){
                ans = Math.min(ans, n - i);
            }
        }
        int ed = 1;
        for(int i = 0;i < n;i++){
            ed = Math.max(ed, i + 1);
            while(ed < n && prefix[i] + suffix[ed] > x){ed++;}
            if(ed < n && prefix[i] + suffix[ed] == x){ans = Math.min(ans, i + 1 + (n - ed));}
        }
        return ans == n + 1 ? -1 : ans;
    }
}
