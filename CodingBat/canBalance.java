public boolean canBalance(int[] nums) {
  int tot = 0;
  int sz = nums.length;
  for(int i = 0 ; i<sz ; i++){
    tot+=nums[i];
  }
  int sum = 0;
  for(int i = 0 ; i < sz ; i++){
    sum+=nums[i];tot-=nums[i];
    if(sum==tot){return true;}
  }
  return false;
}
