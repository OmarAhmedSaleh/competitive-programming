class Solution {

  // Method to sort a string alphabetically 
  public String sortString(String inputString) 
    { 
        // convert input string to char array 
        char tempArray[] = inputString.toCharArray(); 
        // sort tempArray 
        Arrays.sort(tempArray); 
          
        // return new sorted string 
        return new String(tempArray); 
    } 
  public List<Integer> getFreq(String word){
       List<Integer> freq = new ArrayList<Integer>();
    word = sortString(word);
    int st = 0, ed = 0;
    while(st < word.length()){
      while(ed + 1 < word.length() && word.charAt(ed + 1) == word.charAt(st)){ed++;}
      freq.add(ed - st + 1);
      ed++; st = ed;
    }
    Collections.sort(freq);
    return freq;
  }
  public boolean containTheSameCharacters(String word1, String word2){
    for(char c = 'a' ; c <= 'z'; c++){
       int cnt = 0;
       for(int i = 0;i < word1.length();i++){if(word1.charAt(i) == c){cnt = 1;break;}}
       for(int i = 0;i < word2.length();i++){if(word2.charAt(i) == c){cnt++;break;}}
       if(cnt == 1){return false;}       
     }
    return true;
  }
   public boolean closeStrings(String word1, String word2) {
      if(word1.length() != word2.length()){return false;}
     List<Integer> freq1 = getFreq(word1);
     List<Integer> freq2 = getFreq(word2);
     if(!containTheSameCharacters(word1, word2)){return false;}
     if(freq1.size() != freq2.size()){return false;}
      for(int i = 0;i < freq1.size();i++){
        int a = freq1.get(i);
        int b = freq2.get(i);
        if(a != b){return false;}
      }
      return true;
    }
};
