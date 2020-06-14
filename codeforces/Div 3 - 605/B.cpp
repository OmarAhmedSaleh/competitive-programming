#include <iostream>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    string s;
    while(tc-->0){
        cin >> s;
        int n = (int)s.size();
        int l = 0 , r = 0 , d = 0 , u = 0;
        for(int i = 0;i < n ;i++){
            l += s[i] == 'L';
            r += s[i] == 'R';
            d += s[i] == 'D';
            u += s[i] == 'U';
        }
        if(!l || !r || !u || !d){
            if(u && d){
                cout << 2 << endl;
                cout << "UD" << endl;
                continue;
            }
            if(r && l){
                cout << 2 << endl;
                cout << "RL" << endl;
                continue;
            }
        }
        if(l > 0 && r > 0 && d > 0 && u > 0){
            int lr = min(r , l);
            int du = min(d , u);
            cout << (lr + du) * 2 << endl;
            for(int i = 0 ; i < lr ; i++){
                cout << "R";
            }
            for(int i = 0 ; i < du ; i++){
                cout << "U";
            }
            for(int i = 0 ; i < lr ; i++){
                cout << "L";
            }
            for(int i = 0 ; i < du ; i++){
                cout << "D";
            }
            cout << endl;
            continue;
        }
        cout << "0" << endl << endl;
     }
 
    return 0;
}
