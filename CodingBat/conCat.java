public String conCat(String a, String b) {
  String ret = a;
  int i = 0 ;
  int b_len = b.length();
  int a_len = a.length();
  if(a_len>0 && b_len>0 && b.charAt(0)==a.charAt(a.length()-1)){
    i = 1;
  }
  while(i<b_len){
    ret+=b.charAt(i);
    i++;
  }
  return ret;
}
