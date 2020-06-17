#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n;
        cin >> n;
        if((n / 2) % 2 != 0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        vector < int > out;
        out.push_back(1);
        out.push_back(2);
        while((int)out.size() < n){
            int bk = out.back();
            out.push_back(bk + 2);
            out.push_back(bk + 3);
        }
        sort(out.begin() , out.end());
        int st = n / 2;
        for(int i = 0;i < n / 2; i++){
            while(st < n && out[st] % 2 != 0){st++;}
            if(out[i] % 2 != 0 && st < n && out[st] % 2 == 0){
                swap(out[i] , out[st]);
            }
        }
        for(int i = 0 ;i < n ;i++){
            if(i){cout << " ";}
            cout << out[i]; 
        }
        cout << endl;
    }
 
    return 0;
}
