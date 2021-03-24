class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ans((int)A.size(),0);
        vector<pair<int,int>> bIdx;
        for(int i =0;i < (int)B.size();i++) bIdx.push_back({B[i], i});
        sort(bIdx.begin(), bIdx.end());
        sort(A.begin(), A.end());
        int ptr = 0, ptr2 = (int)A.size() - 1;
        for(int i = (int)bIdx.size() - 1;i > -1; i--){
            if(bIdx[i].first < A[ptr2]){
                ans[bIdx[i].second] = A[ptr2--];
            }else{
                ans[bIdx[i].second] = A[ptr++];
            }
        }
        return ans;
    }
};
