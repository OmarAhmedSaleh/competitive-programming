class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<int> can(sz,0);
        can[sz-1] = 1;
        for(int i=sz-2;i>-1;i--){
            for(int j = 1;j<=nums[i]&&(i+j)<sz;j++){
                can[i]|=can[i+j];
            }
        }
        return can[0];
    }
};
