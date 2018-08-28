class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m,vector<int>(n,0));
        ways[0][0] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i){
                    ways[i][j]+=ways[i-1][j];
                }
                if(j){
                    ways[i][j]+=ways[i][j-1];
                }
            }
        }
        return ways[m-1][n-1];
    }
};
