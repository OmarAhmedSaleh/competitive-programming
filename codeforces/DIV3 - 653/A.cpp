#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
 
using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc-- > 0){
	  int x , y , n;
	  cin >> x >> y >> n;
	  int cur = (n / x) * x;
	  if(cur + y <= n){
	    cout << cur + y << endl;
	  }else{
	    cout << cur - (x - y) << endl;
	  }
	}
	  return 0;
}
