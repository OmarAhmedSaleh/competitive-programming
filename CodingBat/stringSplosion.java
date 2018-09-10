public String stringSplosion(String str) {
  String ret = "";
  String s = "";
  int sz = str.length();
  for(int i = 0 ;i<sz;i++){
    s+=str.charAt(i);
    ret+=s;
  }
  return ret;
}
