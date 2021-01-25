class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int prevOne = -1;
        for(int i = 0;i < nums.length;i++){
            if(nums[i] == 1){
                if(prevOne > - 1 && i - prevOne < k + 1){return false;}
                prevOne = i;
            }
        }
        return true;
    }
}
