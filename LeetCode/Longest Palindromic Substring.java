class Solution {
    int[][] memo;
    int solve(int i, int j, String s){
        if(i > j){return 0;}
        if(i + 1 == j || i == j){return s.charAt(i) == s.charAt(j) ? 1 : 0;}
        if(memo[i][j] != -1){return memo[i][j];}
        int ans = s.charAt(i) == s.charAt(j) ? 1 : 0;
        ans &= solve(i + 1, j - 1, s);
        return memo[i][j] = ans;
    }
    public String longestPalindrome(String s) {
        memo = new int[s.length()][s.length()];
        for(int i = 0;i< s.length();i++){
            for(int j = 0;j < s.length();j++){
                memo[i][j] = -1;
            }
        }
        int len = 0, from = 0;
        for(int i = 0;i < s.length();i++){
            for(int j = i;j < s.length();j++){
                if(solve(i,j, s) == 1 && j - i + 1 > len){
                    len = j - i + 1;
                    from = i;
                }
            }
        }
        return s.substring(from, from + len);
    }
}
