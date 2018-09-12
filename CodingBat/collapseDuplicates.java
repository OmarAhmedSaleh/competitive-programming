public String collapseDuplicates(String a) {
  String ret = "";
  int len = a.length();
  for(int i = 0;i<len;i++){
    if(ret.length()>0 && a.charAt(i)==ret.charAt(ret.length()-1)){
      continue;
    }
    ret+=a.charAt(i);
  }
  return ret;
}
