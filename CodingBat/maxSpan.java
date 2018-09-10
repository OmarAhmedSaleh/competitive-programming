public int maxSpan(int[] nums) {
  int sz = nums.length;
  int mx = 0;
  for(int i = 0; i<sz; i++){
    for(int j = i; j>-1;j--){
      if(nums[i]==nums[j]){
        if(mx <= (i-j)){
          mx = (i-j)+1;
        }
      }
    }
  }
  return mx;
}
