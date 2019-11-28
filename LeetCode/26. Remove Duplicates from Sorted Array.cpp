class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st = 1;
        while(st < (int)nums.size()){
            int bk = nums.back();
            nums.pop_back();
            while(nums.size() > 0 && nums.back() == bk){
                nums.pop_back();
            }
            nums.push_back(bk);
            if(st < (int)nums.size() && nums[st] == nums[st - 1]){
                swap(nums[st - 1] , nums[(int)nums.size() - 1]);
                nums.pop_back();
            }
            st++;
        }
        sort(nums.begin() , nums.end());
        return (int)nums.size();
    }
};
