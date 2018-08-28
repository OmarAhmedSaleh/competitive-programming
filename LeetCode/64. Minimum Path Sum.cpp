class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = (int) grid.size();
        int c = (int) grid[0].size();
        const int MAX  = 2e9;
        vector<vector<int>> dis(r,vector<int>(c,MAX));
        dis[0][0] = grid[0][0];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i){
                    dis[i][j] = min(dis[i][j],dis[i-1][j]+grid[i][j]); 
                }
                if(j){
                    dis[i][j] = min(dis[i][j],dis[i][j-1]+grid[i][j]);
                }
            }
        }
        return dis[r-1][c-1];
    }
};
