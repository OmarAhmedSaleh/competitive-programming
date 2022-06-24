class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const int MAX = 2001;
        const int OFFSET = 1000;
        const int NOT_FOUND = 0;
        const int FIRST_ARRAY = 1;
        const int SECOND_ARRAY = 2;
        const int COMMON = 3;
        vector<int> mark(MAX, NOT_FOUND);
        for(int i = 0;i < (int)nums1.size();i++){
            mark[nums1[i] + OFFSET] = FIRST_ARRAY;
        }
        
        for(int i = 0;i < (int)nums2.size();i++){
            if(mark[nums2[i] + OFFSET] != SECOND_ARRAY && mark[nums2[i] + OFFSET] != NOT_FOUND){
                mark[nums2[i] + OFFSET] = COMMON;
            }else{
                mark[nums2[i] + OFFSET] = SECOND_ARRAY;
            }
        }
        vector<vector<int>> ans(2);
        for(int i = 0;i < MAX; i++){
            if(mark[i] != FIRST_ARRAY && mark[i] != SECOND_ARRAY) continue;
            ans[mark[i] - 1].push_back(i - OFFSET);
        }
        return ans;
    }
};
