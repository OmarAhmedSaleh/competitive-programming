// https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=recursion-backtracking
#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
int stepPerms(int n) {
    int dp[n + 1];
    for(int i = 0; i <= n;i++){dp[i] = 0;}
    dp[0] = 1;
    int jump[3] = {1,2,3};
    for(int i = 1;i <= n ; i++){
        for(int j = 0;j < 3; j++){
            if(i - jump[j] < 0){break;}
            dp[i] += dp[i - jump[j]];
        }
    }
    return dp[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
