#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    string s = "";
    int number = 0;
    while((int)s.size() < k){
      number++;
      int temp = number;
      string str = "";
      while(temp != 0){
        str += (temp % 10) + '0';
        temp /= 10;
      }
      reverse(str.begin() , str.end());
      s += str;
    }
    cout << s[k - 1] << endl;
    return 0;
    
} 
