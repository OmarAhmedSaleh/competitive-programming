#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n , l;
    string s;
    cin >> n >> l >> s;
    char c;
    map < char , int > mp;
    for(int i = 0;i < l ;i++){
        cin >> c;
        mp[c] = 1;
    }
    int st = 0;
    s += '&';
    long long ans = 0;
    for(int i = 0;i < (int)s.size();i++){
        if(!mp.count(s[i])){
            int len = i - st;
            // cout << len << endl;
            ans += (1LL * len * (len + 1)) / 2;
            st = i + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
