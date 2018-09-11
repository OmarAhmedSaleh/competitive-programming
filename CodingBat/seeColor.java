public String seeColor(String str) {
  int sz = str.length();
  if(sz>2){
    if(str.substring(0,3).equals("red")){
      return "red";
    }
    if(sz>3&&str.substring(0,4).equals("blue")){
      return "blue";
    }
  }
  return "";
}
