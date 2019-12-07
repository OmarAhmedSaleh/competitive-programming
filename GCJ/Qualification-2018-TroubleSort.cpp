#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    for(int tc = 1 ; tc <= Q; tc++){
      int n;
      cin >> n;
      vector < int > v(n);
      for(int i = 0;i < n ; i++){
          cin >> v[i];
      }
      vector < vector < int >  > p(2);
      for(int i = 0 ; i < 2 ; i++){
          for(int j = i ; j < n ; j += 2){
              p[i].push_back(v[j]);
          }
          if((int)p[i].size()){
              sort(p[i].begin() , p[i].end());
          }
      }
      int idx[2] = {0 , 0};
      int turn  = 0;
      vector < int > merge;
      for(int i = 0;i < n ; i++){
          merge.push_back(p[turn][idx[turn]]);
          idx[turn]++;
          turn ^= 1;
      }
      int ans = -1;
      sort(v.begin() , v.end());
      for(int i = 0;i < n ; i++){
          if(v[i] != merge[i]){
              ans = i;
              break;
          }
      }
      cout << "Case #" << tc << ": ";
      if(ans != -1){
          cout << ans << endl;
      }else{
          cout << "OK" << endl;
      }
    }
    return 0;
} 
