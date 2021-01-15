class Solution {
    private int findBestPosition(List<Integer> seq, int x){
        int low = 0, high = seq.size() - 1, best = seq.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(seq.get(mid) < x){low = mid + 1;}else{
                high = mid - 1;
                best = mid;
            }
        }
        return best;
    }
    public int lengthOfLIS(int[] nums) {
        int LIS = 0;
        List<Integer> seq = new ArrayList<Integer> ();
        for(int i = 0;i < nums.length;i++){
            // find position to allocate nums[i];
            int best = this.findBestPosition(seq,nums[i]);
            if(best == seq.size()){seq.add(nums[i]);}
            seq.set(best, nums[i]);
            LIS = Math.max(best + 1, LIS);
        }
        return LIS;
    }
}
