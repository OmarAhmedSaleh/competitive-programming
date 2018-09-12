public boolean evenlySpaced(int a, int b, int c) {
  int temp = 0;
  int[] arr = {a,b,c};
  for(int i = 0 ; i<3; i++){
    for(int j =i+1;j<3;j++){
      if(arr[i]<arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  a = arr[0]; b = arr[1]; c = arr[2];
  int df_ba = b - a;
  int df_cb = c - b;
  return df_ba==df_cb;
}
