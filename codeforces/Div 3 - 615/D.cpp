#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int q , x;
    cin >> q >> x;
    int curMEX = 0;
    vector < int > uncoveredByMod(x , 0);
    int y;
    for(int i = 0;i < q; i++){
        cin >> y;
        uncoveredByMod[y % x]++;
        while(uncoveredByMod[curMEX % x] > (curMEX / x)){curMEX++;}
        cout << curMEX << endl;
    }
    return 0;
}
