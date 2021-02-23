class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = r > 0 ? matrix.back().size() : 0;
        if(r < 1 || c < 1){return false;}
        for(int i = 0; i < r; i++){
            if(target >= matrix[i][0] && target <= matrix[i].back() && binary_search(matrix[i].begin(), matrix[i].end(), target)){
                return true;
            }
        }
        return false;
    }
};
