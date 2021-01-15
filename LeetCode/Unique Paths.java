class Solution {
    int[][] memo;
    int getWays(int i, int j, int m , int n){
        if(i < 0 || j < 0 || i >= m || j >= n){return 0;}
        if(i + 1 == m && j + 1 == n){return 1;}
        if(memo[i][j] != -1){return memo[i][j];}
        return memo[i][j] = getWays(i + 1, j , m , n) + getWays(i , j + 1, m ,n);
        
    }
    public int uniquePaths(int m, int n) {
        memo = new int[m + 1][n + 1];
        for(int i = 0;i < m;i++){
            for(int j = 0; j < n; j++){
                memo[i][j] = -1;
            }
        }
        return getWays(0,0,m,n);
    }
}
