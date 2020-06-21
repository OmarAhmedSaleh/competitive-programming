class Solution {
public:
  int dynamicProgramming(vector < int > rating){
    int n = (int)rating.size();
    vector < vector < int > > dp(n , vector < int > (3 , 0));
    for(int i = 0;i < n ; i++){
      dp[i][0] = 1;
    }
    for(int i = 0;i < n ;i++){
        for(int j = 0;j < 2 ; j++){
          if(!dp[i][j]){continue;}
          for(int k = i ; k < n ; k++){
            if(rating[i] < rating[k]){
              dp[k][j + 1] += dp[i][j];
            }
          }
        }
      }
    int sum = 0;
    for(int i = 0;i < n ; i++){
      sum += dp[i][2];
    }
    return sum ;
  }
  int less(vector < int > rating){
    return dynamicProgramming(rating);
  }
  int greater(vector < int > rating){
    for(int i = 0;i < (int)rating.size(); i++){
      rating[i] *= -1;
    }
    return dynamicProgramming(rating);
  }
    int numTeams(vector<int>& rating) {
      return less(rating) + greater(rating);
    }
};
