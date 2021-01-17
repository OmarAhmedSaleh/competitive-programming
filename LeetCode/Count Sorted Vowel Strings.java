class Solution {
    int[][] memo;
    int solve(int n , int m){
        if(n < 0){return 1;}
        if(memo[n][m] !=-1){return memo[n][m];}
        int ans = 0;
        for(int c = m; c > -1; c--){
            ans += solve(n - 1, c);
        }
        return memo[n][m] = ans;
    }
    public int countVowelStrings(int n) {
        memo = new int[n][5];
        for(int i = 0;i < n ;i++){
            for(int j = 0;j < 5;j++){
                memo[i][j] = -1;
            }
        }
        return solve(n - 1, 4);
    }
}
