public int sumNumbers(String str) {
  int len = str.length();
  int ret = 0;
  int num = 0;
  for(int i = 0 ;i<len ; i++){
    if(Character.isDigit(str.charAt(i))){
      num*=10;
      num+=str.charAt(i)-'0';
    }
    if(!Character.isDigit(str.charAt(i)) || (i+1)==len){
      ret+=num;
      num = 0;
    }
  }
  return ret;
}
