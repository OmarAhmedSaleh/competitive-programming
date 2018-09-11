public Map<String, String> pairs(String[] strings) {
  Map<String,String> ret = new HashMap<String,String>();
  int sz = strings.length;
  for(int i = 0 ; i<sz ; i++){
    if(!ret.containsKey(strings[i])){
      ret.put(""+strings[i].charAt(0),""+strings[i].charAt(strings[i].length()-1));
    }
  }
  return ret;
}
