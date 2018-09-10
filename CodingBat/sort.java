int[] sort(int[] a) {
  int sz = a.length;
  for(int i = 0 ;i<sz; i++){
    for(int j = i-1;j>-1;j--){
      if(a[i]<a[j]){
        int aa = a[i];
        a[i]=a[j];
        a[j]=aa;
      }
    }
  }
  int cnt = 0;
  for(int i=0;i<sz;i++){
    if((i==0) || (a[i]!=a[i-1])){cnt++;}
  }
  int[] ret = new int[cnt];
  int idx = 0;
  for(int i=0;i<sz;i++){
    if((i==0)|| a[i]!=a[i-1]){
      ret[idx++]=a[i];
    }
  }
  return ret;
}
