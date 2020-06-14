#include <iostream>

using namespace std;

int main(){
    int tc;
    cin >> tc;
    for(int tt = 0; tt < tc ; tt++){
        int a[3];
        int x[3] = {0 , 1 , -1};
        for(int i = 0;i < 3 ; i++){
            cin >> a[i];
        }
        long long ans = 1e11;
        for(int i = 0;i < 3 ; i++){
            for(int j = 0;j < 3 ; j++){
                for(int k = 0;k < 3; k++){
                    int aa = a[0] + x[i];
                    int bb = a[1] + x[j];
                    int cc = a[2] + x[k];
                    ans = min(ans , 1LL * abs(aa - bb) + abs(bb - cc) + abs(cc - aa));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
