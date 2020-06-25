class Solution {
public:
    string addStrings(string num1, string num2) {
      if((int)num1.size() < (int)num2.size()){
        swap(num1 , num2);
      }
      int dif = (int)num1.size() - (int)num2.size();
      reverse(num1.begin() , num1.end());
      reverse(num2.begin() , num2.end());
      while(dif--){
        num2 += '0';
      }
      int c = 0 , length = (int)num1.size();
      string ans = "";
      for(int i = 0;i < length ;i++){
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';
        if(c == 1){
          digit1++;
        }
        c = 0;
        int sum = digit1 + digit2;
        if(sum >= 10){
          c = 1;
          sum -= 10;
        }
        ans += sum + '0';
      }
      if(c == 1){
        ans += '1';
      }
      reverse(ans.begin() , ans.end());
      return ans;
    }
};
