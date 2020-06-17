#include <iostream>

using namespace std;

int main(){
   ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n , a , b , c;
        cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        int d = sum / 3;
        string ans = "YES";
        if(sum % 3 != 0 || d < max(a , max(b , c))){
            ans = "NO";
        }
        cout << ans << endl;
    }
    return 0;
}
