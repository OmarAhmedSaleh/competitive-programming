#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
void count(int &n , int d , int &ans , int inc){
  while(n > 0 && n % d == 0){
    n /= d;
    ans += inc;
  }
}
int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc-- > 0){
	  int n;
	  cin >> n;
	  int ans = 0;
	  count(n , 6 , ans , 1);
	  count(n , 3 , ans , 2);
	  ans = n == 1 ? ans : -1;
	  cout << ans << endl;
 
	}
	  return 0;
}
