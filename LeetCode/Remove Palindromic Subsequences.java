class Solution {
    public boolean isPalindrom(String s){
        int start = 0, end = s.length() - 1;
        // handle empty string
        if(end < 0){return false;}
        
        while(end >= start){
            if(s.charAt(start) != s.charAt(end)){
                return false;
            }
            end--; start++;
        }
        return true;
    }
    public int removePalindromeSub(String s) {
        int a = 0, b = 0;
        for(int i = 0;i < s.length(); i++){
            char c = s.charAt(i);
            if(c == 'a'){a = 1;}
            if(c == 'b'){b = 1;}
        }
        return isPalindrom(s) ? 1 : a + b;
    }
}
