public Map<String, Integer> word0(String[] strings) {
  Map<String,Integer> ret = new HashMap<String,Integer>();
  int sz = strings.length;
  for(int i = 0 ; i<sz; i++){
    if(!ret.containsKey(strings[i])){
      ret.put(strings[i],0);
    }
  }
  return ret;
}
