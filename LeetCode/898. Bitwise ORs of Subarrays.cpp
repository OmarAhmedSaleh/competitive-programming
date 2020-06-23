class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
      int n = A.size();
      vector < vector < int > > ids(32);
      for(int i = n - 1; i > -1 ;i--){
        for(int bit = 0; bit < 32; bit++){
          if(A[i] & (1 << bit)){
            ids[bit].push_back(i);
          }
        }
      }
      unordered_set <long long> allNumbers; 
      for(int i = 0;i < n ; i++){
        long long currentNumber = A[i];
        bool found = true;
        while(found){
          allNumbers.insert(currentNumber);
          found = false;
          int best = n + 1;
          for(int bit = 0; bit < 32; bit++){
            if(!(currentNumber & (1 << bit)) && (int)ids[bit].size() > 0){
              int index = ids[bit].back();
              if(index > i){
                best = min(best , index);
                found = true;
              }
            }
          }
          if(found){
            currentNumber |= A[best];
          }
        }
         for(int bit = 0; bit < 32; bit++){
          if(A[i] & (1 << bit)){
            ids[bit].pop_back();
          }
         }
      }
      return (int)allNumbers.size();
    }
};
