public String lastTwo(String str) {
  int sz = str.length();
  String ret = "";
  
  if(sz>1){
    for(int i = 0 ;i<sz-2;i++){
    ret+=str.charAt(i);
    }
    ret+=str.charAt(sz-1);
    ret+=str.charAt(sz-2);
  }else{
    ret+=str;
  }
  return ret;
}
