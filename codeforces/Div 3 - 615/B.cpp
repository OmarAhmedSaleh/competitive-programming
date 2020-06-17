#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector < pair < int , int > > p(n);
        for(int i = 0;i < n ;i++){
            cin >> p[i].first >> p[i].second;
        }
        sort(p.begin() , p.end());
        int x = 0 , y = 0;
        bool can = true;
        string ans = "";
        for(int i = 0; i < n;i++){
            if(p[i].first < x || p[i].second < y){
                can = false;
                break;
            }
            // right 
            int dif_x = p[i].first - x;
            while(dif_x--){ans += 'R'; x++;}
            // up
            int dif_y = p[i].second - y;
            while(dif_y--){ans += 'U'; y++;}
        }
        if(!can){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl << ans << endl;
        }
    }
    return 0;
}
