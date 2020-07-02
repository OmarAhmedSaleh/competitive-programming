class Solution {
public:
  string convIntToString(int n){
    string str = "";
    while(n > 0){
      int dig = n % 10;
      n /= 10;
      str += dig + '0';
    }
    reverse(str.begin() , str.end());
    return str;
  }
  void sortSubString(string &str , int sz , int mnIndex){
     for(int i = mnIndex ; i < sz; i++){
      for(int j = i + 1; j < sz ; j++){
        if(str[i] > str[j]){
          swap(str[i] , str[j]);
        }
      }
    }
  }
  pair < bool , string > getNextNumber(string str){
    int sz = (int)str.size();
      bool found = false;
      for(int i = sz - 1 ;i > -1 ;i--){
        int mnIndex = i;
        for(int j = i + 1 ; j < sz ;j++){
          if(str[i] < str[j] && (!found || str[mnIndex] > str[j])){
            found = true;
            mnIndex = j;
          }
        }
        if(found){
          swap(str[i] , str[mnIndex]);
          sortSubString(str , sz , i + 1);
          break;
        }
      }
   
    return {found , str};
  }
  int convStringToInt(string str){
    int sz = (int)str.size();
    long long n = 0;
    for(int i = 0;i < sz ; i++){
      n *= 10;
      n += str[i] - '0';
    }
    if(n > INT_MAX){
      return -1;
    }
    return (int)n;
  }
    int nextGreaterElement(int n) {
        if(n < 12){
          return -1;
        }
      pair < bool , string > p = getNextNumber(convIntToString(n));
      if(!p.first){
        return -1;
      }
      return convStringToInt(p.second);
    }
};
