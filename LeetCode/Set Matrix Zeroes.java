class Solution {
    public void setZeroes(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int firstCol = 0, firstRow = 0;
        for(int i = 0;i < n ;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 0){
                    if(i == 0){firstRow = 1;}
                    if(j == 0){firstCol = 1;}
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = n - 1; i > 0; i--){
            for(int j = 1;j < m;j++){
                if(matrix[i][0] != 0){break;}
                matrix[i][j] = 0;
            }
        }
        for(int j = 1;j < m;j++){
            if(matrix[0][j]!=0){continue;}
            for(int i = 0;i < n;i++){
                matrix[i][j] = 0;
                
            }
        }
        if(firstRow == 1){for(int i = 0;i < m;i++){matrix[0][i] = 0;}}
        if(firstCol == 1){for(int i = 0;i < n;i++){matrix[i][0] = 0;}}
    }
}
