public Map<String, String> mapShare(Map<String, String> map) {
  Map< String , String> ret = new HashMap<String,String>();
  ret = map;
  if(ret.containsKey("c")){
    ret.remove("c");
  }
  if(ret.containsKey("a")){
    if(ret.containsKey("b")){
      ret.remove("b");
    }
    ret.put("b",ret.get("a"));
  }
  return ret;
}
