 // https://www.hackerrank.com/challenges/construct-the-array/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int N = 1e5, MOD = 1e9 + 7;
long long memo[N][2];
int n, k;
long long solve(int idx, int prevEqX){
    if(idx == n){
        return 0;
    }
    if(memo[idx][prevEqX]!=-1){return memo[idx][prevEqX];}
    if(idx + 1 == n){
        return 1 - prevEqX;
    }
    long long ans = 0;
    if(prevEqX){
        ans += solve(idx + 1 , 0) * (k - 1);
    }else{
        ans += solve(idx + 1, 0) * (k - 2) + solve(idx + 1 , 1);
    }
    return memo[idx][prevEqX] = ans % MOD;
}


long countArray(int nn, int kk, int x) {
    // Return the number of ways to fill in the array.
    memset(memo, -1, sizeof(memo));
    n = nn; k = kk;
    return solve(1, x == 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
