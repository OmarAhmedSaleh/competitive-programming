class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int right = 0 , left = (int)nums.size()-1;
        while(right<=left){
            int mid = (left+right)>>1;
            int len = mid - right ;
            len++;
            if(len&1){
                if(len>1){
                    if(nums[mid-1]==nums[mid-2]){
                        right = mid;
                    }else{
                        left = mid-1;
                    }
                }else{
                    if(len == 1){
                        return nums[mid];
                    }
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    right = mid+1;
                }else{
                    left = mid;
                }
            }
            
        }
        return nums[right];
    }
};
