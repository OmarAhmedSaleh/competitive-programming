class Solution {
   
    public boolean canPop(Stack<Character> st, char b){
        if(st.size() == 0){return false;}
        char a = st.peek();
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'); 
    }
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for(int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            if(canPop(st, c)){st.pop();}else{st.push(c);}
        }
        return st.size() == 0 ? true: false;
        
    }
}
