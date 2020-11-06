// https://www.hackerrank.com/challenges/short-palindrome/copy-from/186944715
#include <bits/stdc++.h>

using namespace std;

// Complete the shortPalindrome function below.
int shortPalindrome(string s) {
    const int MOD = 1e9 + 7;
    long long dp[26][26][4];
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 26;j++){
            for(int k =0;k < 4;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int i = 0;i < (int)s.size();i++){
        int letIndex = s[i] - 'a';
        for(int j = 0;j < 26;j++){
            dp[letIndex][j][3] += dp[letIndex][j][2] % MOD;
            dp[j][letIndex][2] += dp[j][letIndex][1] % MOD;            
            dp[j][letIndex][1] += dp[j][letIndex][0] % MOD;
            dp[letIndex][j][0]++;
            for(int d = 0; d < 4; d++){
                dp[letIndex][j][d] %= MOD;
                dp[j][letIndex][d] %= MOD;
                
            }
        }
    }
    long long ans = 0;
    for(int i = 0;i < 26;i++){
        for(int j = 0;j < 26;j++){
            ans = (ans  + dp[i][j][3]) % MOD;
        }
    }
    return ans % MOD;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = shortPalindrome(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
