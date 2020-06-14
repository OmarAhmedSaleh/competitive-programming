#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    vector<int> r(n,1) , a(n) , l(n,1);
    for(int i =0;i < n ; i++){
        cin >> a[i];
    }
    for(int i = 1 ; i < n ; i++){
        if(a[i] > a[i - 1]){
            l[i] += l[i - 1];
        }
    }
    for(int i = n - 2; i > -1 ; i--){
        if(a[i] < a[i + 1]){
            r[i] += r[i + 1];
        }
    }
    int ans = 0;
    for(int i = 0 ;i < n ;i++){ans = max(ans , r[i]);}
    for(int i = 1;i < n - 1; i++){
        if(a[i - 1] < a[i + 1]){
            ans = max(ans , l[i - 1] + r[i + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
