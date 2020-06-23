class Solution {
public:
    int maxLength(vector<string>& arr) {
      int n = (int)arr.size();
      int best = 0;
      for(int mask = 0;mask < 1 << n ; mask++){
        vector < int > mark(26 , 0);
        bool bad = false;
        int cnt = 0;
        for(int i = 0;i < n ;i++){
          if(mask & (1 << i)){
            for(auto c : arr[i]){
              if(mark[c - 'a']){
                bad = true;
                break;
              }
              mark[c - 'a'] = 1;
              cnt++;
            }
          }
        }
        if(!bad){
          best = max(best , cnt);
        }
      }
      return best;
    }
};
