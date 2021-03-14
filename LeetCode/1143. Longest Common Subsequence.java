class Solution {
    private class Solver{
        private final int NOT_CALCULATED = -1;
        private int[][]memo;
        private String text1, text2;
        public Solver(String text1, String text2){
            this.text1 = text1;
            this.text2 = text2;
             memo = new int[text1.length()][text2.length()];
            for(int i = 0;i < text1.length();i++){
                for(int j = 0;j < text2.length(); j++){
                    memo[i][j] = NOT_CALCULATED;
                }
            }
        }
        public int solve(){
            return this.solve(0,0);
        }
        private int solve(int ptr1, int ptr2){
            if(ptr1 == text1.length() || ptr2 == text2.length()){
                return 0;
            }
            if(memo[ptr1][ptr2 ]!= NOT_CALCULATED){return memo[ptr1][ptr2];}
            int ans = Math.max(solve(ptr1 + 1, ptr2), solve(ptr1, ptr2 + 1));
            if(text1.charAt(ptr1)==text2.charAt(ptr2)){
                ans = Math.max(solve(ptr1 + 1, ptr2 + 1) + 1, ans);
            }
            return memo[ptr1][ptr2] = ans;
        }
    }

    public int longestCommonSubsequence(String text1, String text2) {
        Solver solver = new Solver(text1, text2);
        return solver.solve();
    }
}
