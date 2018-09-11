public String[] encoder(String[] raw, String[] code_words) {
  int sz = raw.length;
  String[] ret = new String[sz];
  int pos = 0;
  for(int i = 0 ; i < sz ; i++){
    int j  = i-1;
    boolean done = false;
    while(j>-1){
      if(raw[i]==raw[j]){
        ret[i]=ret[j];
        done = true;
        break;
      }
      j--;
    }
    if(!done){
      ret[i] = code_words[pos];
      pos++;
    }
  }
  return ret;
}
