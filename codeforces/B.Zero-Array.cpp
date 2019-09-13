#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    long long sum = 0;
    for(int i = 0;i < n ; i++){
      cin >> v[i];
      sum += v[i];
    }
    if(sum & 1){
      cout << "NO" << endl;
      return 0;
    }
    long long h = sum / 2;
    sort(v.rbegin() , v.rend());
    vector < int > a , b;
    for(int i = 0; i < n ; i++){
      if(v[i] <= h){
        h -= v[i];
        a.push_back(v[i]);
      }else{
        b.push_back(v[i]);
      }
    }
    if(h == 0){
      cout << "YES" << endl;
    }else{
      int need = h;
      reverse(b.begin() , b.end());
      for(int i = 1; i < (int)b.size() ; i++){
        long long mn = min(h , 1LL * min(b[i] , b[i - 1]));
        h -= mn;
        b[i] -= mn;
        b[i - 1] -= mn;
      }
      
      if(h == 0){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }
    }
    
    
    return 0;
    
} 
