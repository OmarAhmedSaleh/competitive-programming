class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (s1, s2) -> Integer.compare(s2.length(), s1.length()));
        Map<String, Boolean> dic = new HashMap<String,Boolean>();
        int ans = 0;
        for(String word: words){
            String reversedWord = new StringBuilder(word).reverse().toString();
            if(dic.containsKey(reversedWord)){continue;}
            ans += reversedWord.length() + 1;
            StringBuilder wordBuilder = new StringBuilder("");
            for(int i = 0;i < reversedWord.length();i++){
                char c = reversedWord.charAt(i);
                wordBuilder.append(c);
                dic.put(wordBuilder.toString(), true);
            }
        }
        return ans;
    }
}
