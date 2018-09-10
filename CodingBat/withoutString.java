public String withoutString(String base, String remove) {
  String Base = base;
  base = base.toLowerCase();
  remove = remove.toLowerCase();
  int base_sz = base.length();
  int re_sz = remove.length();
  boolean[] change = new boolean[base_sz];
  int st = 0;
  for(int i = 0 ;(i+re_sz)<=base_sz;i++){
    if(change[i]==true){
      continue;
    }
    change[i] = false;
    boolean ok = true;
    for(int j = 0;j<re_sz&&((i+j)<base_sz);j++){
     if(base.charAt(i+j)!=remove.charAt(j)){
       ok = false;
       break;
     }
    }
    if(ok){
      for(int j = 0 ;j<re_sz&&((i+j)<base_sz);j++){
        change[i+j] = true;
      }
    }
  }
  String ret = "";
  for(int i = 0; i<base_sz; i++){
    if(change[i]==true){continue;}
    ret+=Base.charAt(i);
  }
  return ret;
}
