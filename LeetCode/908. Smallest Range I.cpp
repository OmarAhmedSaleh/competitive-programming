class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int mx = 0;
        int mn = 10000;
        int n = (int)A.size();
        for(int i = 0;i < n ; i++){
            mx = max(mx , A[i]);
            mn = min(mn , A[i]);
        }
        int dif = mx - mn;
        if(dif <= 2 * K){
            return 0;
        }
        return mx - mn - 2 * K;
    }
};
