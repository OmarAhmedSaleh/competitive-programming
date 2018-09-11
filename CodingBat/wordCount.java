public Map<String, Integer> wordCount(String[] strings) {
  Map<String,Integer> ret = new HashMap<String,Integer>();
  int sz = strings.length;
  int cnt = 0;
  for(int i = 0 ; i<sz ; i++){
    cnt = 1;
    if(ret.containsKey(strings[i])){
      cnt+=ret.get(strings[i]);
      ret.remove(strings[i]);
    }
    ret.put(strings[i],cnt);
  }
  return ret;
}
