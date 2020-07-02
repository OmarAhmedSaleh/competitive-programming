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
	  int n;
	  string s;
	  cin >> n >> s;
	  vector < char > st;
	  int ans = 0;
	  for(int i = 0;i < n + ans; i++){
	    if(s[i] == ')'){
	      if(st.empty()){
	        ans++;
	        s += ')';
	      }else{
	        st.pop_back();
	      }
	    }else{
	      st.push_back('(');
	    }
	  }
	  cout  << ans << endl;
	}
	  return 0;
}
