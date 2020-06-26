class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      set < int > st;
      unordered_map < int , int > cnt;
      int n = (int)nums.size();
      if(n == 0){
        return false;
      }
      for(int i = 1;i < n ; i++){
        cnt[nums[i]]++;
        st.insert(nums[i]);
      }
      int minSoFar = nums[0];
      for(int i = 1;i < n ; i++){
        cnt[nums[i]]--;
        if(cnt[nums[i]] == 0){
          // remove 
          auto pos = st.find(nums[i]);
          st.erase(pos);
        }
        if(nums[i] > minSoFar){
          auto pos = st.lower_bound(minSoFar);
          while(pos != st.end() && (*pos) <= minSoFar){
            pos++;
          }
          if(pos != st.end() && *pos > minSoFar && *pos < nums[i]){
              return true;
          }
        }else{
          minSoFar = nums[i];
        }
      }
      return false;
    }
};
