class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
      int n = (int)groupSizes.size();
      vector < vector < int > > ans;
      vector < vector < int >  > mark(n + 1);
      for(int i = 0 ; i < n ; i++){
        mark[groupSizes[i]].push_back(i);
      }
      for(int i = 1; i <= n ; i++){
        while((int)mark[i].size() > 0 ){
          vector < int > group;
          while((int)group.size() < i){
            group.push_back(mark[i].back());
            mark[i].pop_back();  
          }
          ans.push_back(group);          
        }
      }
      return ans;
    }
};
