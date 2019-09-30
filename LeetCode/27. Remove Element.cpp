class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = (int)nums.size();
        int ed = n - 1;
        int cnt = 0;
        for(int i = 0;i < n ; i++){
            if(nums[i] == val){
                cnt++;
            }
        }
        for(int i = 0; i < n ; i++){
            while(ed > -1 && nums[ed] == val){
                ed--;    
            }
            if((n - ed) - 1 == cnt){
                break;
            }
            if(nums[i] == val){
                swap(nums[i] , nums[ed]);
            }
        }
        while(!nums.empty() && nums.back() == val){
            nums.pop_back();
        }
        return (int)nums.size();
    }
};
