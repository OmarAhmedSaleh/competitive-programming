#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
 
int main(){
  ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc-- > 0){
	  int n, k;
	  long long ans = 0;
	  cin >> n >> k;
	  vector < long long > needed;
	  vector < int > sortedinput(n);
	  map < long long , long long > last;
	  int x;
	  for(int i = 0;i < n ; i++){
	    cin >> sortedinput[i];
	  }
	  sort(sortedinput.begin() , sortedinput.end());
	  for(int i = 0;i < n ; i++){
	    x = sortedinput[i];
	    if(x % k == 0){
	      continue;
	    }
	    long long rem = k - (x % k);
	    long long need = rem;
	    if(!last.count(rem)){
	      last[rem] = need;
	    }else{
	      if(last[rem] >= need){
	        last[rem] = last[rem] + k;
	        rem = last[rem];
	      }
	    }
	    needed.push_back(rem);
	  }
	  if(!needed.empty()){
	    sort(needed.begin() , needed.end());
	    ans = needed[0] + 1;
	    long long cur = needed[0] + 1;
	    for(int i = 1 ; i < (int)needed.size(); i++){
	      if(needed[i] <= needed[i - 1]){
	        needed[i] = needed[i - 1] + k;
	      }
	      ans += needed[i] - cur + 1;
	      cur = needed[i] + 1;
	    }
	    
	  }
	  cout << ans << endl;
	}
	  return 0;
}
