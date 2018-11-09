class Solution {
public:
    vector< vector< int > > memo;
    int oo = 1e9;
    void setMemo(int n){
        memo.resize(n,vector<int> (n,oo));
    }
    int get(int i , int j , vector<vector<int>> &A){
        if(j >= (int)A.size() || j < 0){
            return oo;
        }
        if(i == (int)A.size()){
            return 0;
        }
        if(memo[i][j] != oo){
            return memo[i][j];
        }
        int ans = oo;
        for(int move = -1 ; move < 2 ; move++){
            ans = min(ans, get(i+1, j + move , A) + A[i][j]);
        }
        return memo[i][j] = ans;
        
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = (int)A.size();
        setMemo(n);
        int ret = oo;
        for(int i = 0 ; i < n ; i++){
            ret = min(ret , get(0, i, A));
        }
        return ret;
    }
};
