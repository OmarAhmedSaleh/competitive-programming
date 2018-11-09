class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector< int > ret;
        int n = (int)nums.size();
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            if((i + 1) < n && nums[i] == nums[i+1]){
                continue;
            }
            ret.push_back(nums[i]);
        }
        return ret;
    }
};
