class Solution {
    public boolean hasAllCodes(String s, int k) {
        int sz = s.length();
        final int MAX = 1 << k;
        boolean[] has = new boolean[MAX];
        for(int i = 0;i < MAX;i++){
            has[i] = false;
        }
        for(int i = 0;i + k - 1 < sz; i++){
            int ed = i + k - 1, N = 0, p = 1;
            while(ed >= i){
                if(s.charAt(ed) == '1'){N += p;}
                p *= 2;
                ed--;
            }
            has[N] = true;
        }
        boolean hasAll = true;
        for(int i = 0;i < MAX; i++){
            hasAll &= has[i];
        }
        return hasAll;
        
    }
}
