#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdio.h>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector < int > v(n);
        for(int i = 0 ;i < n ;i++){
            cin >> v[i];
        }
        vector < int > seq;
        seq.push_back(v[0]);
        for(int i = 1;i < n ;i++){
            if(1LL * seq.back() * v[i] > 0 && v[i] > seq.back()){
                seq.pop_back();
                seq.push_back(v[i]);
            }
            if(1LL * seq.back() * v[i] < 0){
                seq.push_back(v[i]);
            }
        }
        long long ans = 0;
        for(int i = 0;i < (int)seq.size(); i++){
            ans += seq[i];
        }
        cout << ans << endl;
    }


    return 0;
}
