#include <iostream>

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
        long long sum = 1;
        int ans = 0;
        for(int i = 1;i < 33;i++){
            sum += 1 << i;
            if(n % sum == 0){
                ans = n / sum;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
