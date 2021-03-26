#include <bits/stdc++.h>
 
using namespace std;
long long sum(int N){
  if(N < 1){
    return 0;
  }
  long long ret = 1LL * N * (N + 1) / 2;
  return ret;
}
long long cal(int &r, int &d,int &sec, bool first){
  long long ret = 0;
  int l = d;
  if(first){
    int maxCap = sec - d > r ? r : sec - d;
    ret += 1LL * maxCap * d;
    ret += sum( maxCap == r? 0 : d - 1);
    if(d && (r - maxCap) < (d - 1) && r != maxCap){
      ret -= sum((d - 1) - (r - maxCap) );  
    }
  }else{
   ret += 1LL * 2 * sum(sec - 1) - ((sec - 1 > r ? sum((sec - 1) - r) : 0)) - ((sec - 1 > l ? sum((sec - 1) - l) : 0));
  }
  return ret;
}
bool valid(int &n ,int &x , int &y ,int &sec , long long &c){
  int r = min(sec , n - y);
  int l = min(sec , y - 1);
  int u = min(sec , x - 1);
  int d = min(sec , n - x);
  long long switchedOnCells = r + l + d + u + 1;
  if(sec - 1 >= d){
    switchedOnCells += cal(r,d,sec,true);
    switchedOnCells += cal(l,d,sec,true);
  }else{
    switchedOnCells += cal(r,l,sec,false);
  }
  if(sec - 1 >= u){
    switchedOnCells += cal(r,u,sec,true);
    switchedOnCells += cal(l,u,sec,true);
  }else{
    switchedOnCells += cal(r,l,sec,false);
  }
  return switchedOnCells >= c;
}
int getMin(int &n ,int &x , int &y , long long &c){
  int low = 0 , high = 1e9;
  int ans = high;
  int mid = high;
  while(low <= high){
    mid = (high + low) >> 1;
    if(valid(n, x , y, mid , c)){
      ans = ans > mid ? mid : ans;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n , x , y;
  long long c;
  cin >> n >> x >> y >> c;
  cout << getMin(n , x , y , c) << endl;
  return 0;
}
