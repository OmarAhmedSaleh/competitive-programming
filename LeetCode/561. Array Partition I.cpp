class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sz = (int)nums.size();
        sort(nums.begin(),nums.end());
        int ret = 0;
       for(int i=0;i<sz;i+=2){ret+=nums[i];} 
        return ret;
    }
};
