class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int ret = 0;
        vector<int> col((int)grid[0].size()),row((int)grid.size());
        for(int i=0;i<(int)grid.size();i++){
            for(int j=0;j<(int)grid[0].size();j++){
                row[i]=max(row[i],grid[i][j]);
                col[j]=max(col[j],grid[i][j]);
            }
        }
        for(int i=0;i<(int)grid.size();i++){
            for(int j=0;j<(int)grid[0].size();j++){
                ret+=min(row[i],col[j])-grid[i][j];
            }
        }
        return ret;
    }
};
