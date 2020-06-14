#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 202;
const int MAX_BAL = 444;
const int oo = 1e9;
int dp[N][N][MAX_BAL] , n , m;
pair< pair < int , int > , pair < int , char > > parent[N][N][MAX_BAL];
string s, t;
inline void readInput(){
    cin >> s >> t;
     n = (int)s.size();
     m = (int)t.size();
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        for(int k = 0;k < MAX_BAL;k++){
          dp[i][j][k] = oo;
        }
      }
    }
}
inline void dynamicProgramming(){

    dp[0][0][0] = 0;
    parent[0][0][0] = {{-1 , -1} , {-1 , '('}};
    for(int i = 0;i <= n ;i++){
        for(int j = 0;j <= m ;j++){
            for(int bal = 0; bal < MAX_BAL ; bal++){
                if(dp[i][j][bal] == oo){
                    continue;
                }
                int iNext = ( i < n && s[i] == '(')? i + 1 : i;
                int jNext = ( j < m && t[j] == '(')? j + 1 : j;
                if(bal + 1 < MAX_BAL && dp[iNext][jNext][bal + 1] > dp[i][j][bal] + 1){
                    dp[iNext][jNext][bal + 1] = dp[i][j][bal] + 1;
                    parent[iNext][jNext][bal + 1] = {{i , j} , {bal , '('}};
                }
                if(bal > 0){
                    iNext = (i < n && s[i] == ')') ? i + 1 : i;
                    jNext = (j < m && t[j] == ')') ? j + 1 : j;
                    if(dp[iNext][jNext][bal - 1] > dp[i][j][bal] + 1){
                        dp[iNext][jNext][bal - 1] = dp[i][j][bal] + 1;
                        parent[iNext][jNext][bal - 1] = {{i , j} , {bal , ')'}};
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    readInput();
    dynamicProgramming();

    int b = 0;
    for(int i = 0;i < MAX_BAL ;i++){
        if(dp[n][m][i] != oo){
            b = i;
            break;
        }
    }
    string ans = "";
    for(int i = 0;i < b ;i++){ans += ')';}
    int curI = parent[n][m][b].first.first;
    int curJ = parent[n][m][b].first.second;
    int curBal = parent[n][m][b].second.first;
    char curChar = parent[n][m][b].second.second;
    while(curI > -1){
        ans += curChar;
        int i = parent[curI][curJ][curBal].first.first;
        int j = parent[curI][curJ][curBal].first.second;
        int b = parent[curI][curJ][curBal].second.first;
        char c = parent[curI][curJ][curBal].second.second;
        curI = i;curJ = j; curBal = b;curChar = c;
    }
    reverse(ans.begin() , ans.end());
    cout << ans << endl;
    return 0;
}
