class Solution {
   
    public int[] mostCompetitive(int[] nums, int k) {
        Stack<Integer> st = new Stack<Integer>();
        for(int i = 0;i < nums.length;i++){
            while(st.size() > 0 && nums.length - i > k - st.size() && st.peek() > nums[i]){
                st.pop();
            }
            if(st.size() < k){
                st.push(nums[i]);
            }
        }
        System.out.println(st.size());
        int[] ans = new int[k];
        for(int i = 0;i < k; i++){
            ans[k - i - 1] = st.peek();
            st.pop();
        }
        return ans;
        
    }
}
