class Solution {
public:
  void calculatePairSum(vector < int > A , vector< int > B , unordered_map < long long , int > &cnt){
    int n = (int)A.size();
      for(int i = 0;i < n ;i++){
        for(int j = 0; j < n; j++){
          long long sum = 1LL * A[i] + B[j];
          cnt[sum]++;
        }
      }
  }
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
      unordered_map < long long , int > AB , CD;
      calculatePairSum(A , B , AB);
      calculatePairSum(C , D , CD);
      int ans = 0;
      for(auto p : AB){
        ans +=  p.second * CD[-p.first];
      }
      return ans;
    }
};
