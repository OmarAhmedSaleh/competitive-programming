class Solution {
public:
    string removeKdigits(string num, int k) {
        vector < char > st;
      int start = 0 , n = (int)num.size();
      int firstZeroPosition = n + n;
      bool op = true;
      while(op){
        op = false;
        firstZeroPosition = n + n;
       for(int i = start;i < n ; i++){
         if(num[i] == '0'){
           firstZeroPosition = i; 
           break;
         }
       }
       if((firstZeroPosition - start) <= k){
         op = true;
         k -= (firstZeroPosition - start);
         start = firstZeroPosition;
         while(start < n && num[start] == '0'){
           start++;
         }
         if(start == n){
           return "0";
         }
       }  
      }
      while(start < n ){
        while(!st.empty() && st.back() > num[start] && k > 0){
          k--;
          st.pop_back();
        }
        st.push_back(num[start]);
        start++;
    }
   while(k--){
     st.pop_back();
   }
    if((int)st.size() == 0){
     return "0";
   }
    string ans = "";
   for(int i = 0; i < (int)st.size(); i++){
      ans += st[i];
   }
   return ans;
    }
};
