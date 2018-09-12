public boolean makeBricks(int small, int big, int goal) {
  for(int i = 0; i<=small && i<=goal ; i++){
    int rem = goal - i;
    if(rem%5==0 && (rem/5)<=big){
      return true;
    }
  }
  return false;
}
