class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        int sz = (int)nums.size();
        int aa  = -1;
        vector<int> v(3);
        for(int i=0;i<sz;i++){
            if( i && (nums[i]==nums[i-1])){
                continue;
            }
            v[0] = nums[i];
            for(int j=i+1;j<sz;j++){
                if(j && (nums[j]==nums[j-1]) && aa==i){
                    continue;
                }
                aa = i ;
                v[1] = nums[j];
                int pos = (int)(upper_bound(nums.begin(),nums.end(),-(nums[i]+nums[j]))-nums.begin());
                pos--;
                if(pos!=sz && (nums[pos]+nums[i]+nums[j] == 0) && pos>j){
                    v[2] = nums[pos];
                    ret.push_back(v);

                }
            }
        }
        return ret;
    }
};
