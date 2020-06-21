class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector < int > cnt(n + 1 , 0);
      int sz = (int)bookings.size();
      for(int i = 0;i < sz; i++){
        int from = bookings[i][0];
        int to = bookings[i][1];
        int seats = bookings[i][2];
        cnt[from - 1] += seats; 
        cnt[to] -= seats;
      }
      for(int i = 1 ; i < n ; i++){
        cnt[i] += cnt[i - 1];
      }
      cnt.pop_back();
      return cnt;
    }
};
