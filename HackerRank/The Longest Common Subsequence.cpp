#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int N = 1e3;
int memo[N][N];
vector<int> ans;
int solve(int i, int j, vector<int> &a, vector<int> &b){
    if(i == (int)a.size() || j == (int)b.size()){
        return 0;
    }
    if(memo[i][j] != -1){return memo[i][j];}
    int ans = max(solve(i + 1, j, a, b), solve(i, j + 1, a, b));
    if(a[i] == b[j]){
        ans = max(ans, solve(i + 1, j + 1, a, b) + 1);
    }
    return memo[i][j] = ans;
}
void getAns(int i, int j, vector<int> &a, vector<int> &b){
    if(i == (int)a.size() || j == (int)b.size()){
        return ;
    }
    if(solve(i + 1,j,a,b) == memo[i][j]){
        getAns(i + 1, j, a,b);
        return;
    }
    if(solve(i,j + 1,a,b) == memo[i][j]){
        getAns(i, j + 1, a,b);
        return;
    }
    if(a[i] == b[j] && 1 + solve(i + 1,j + 1,a,b) == memo[i][j]){
        ans.push_back(a[i]);
        getAns(i + 1, j + 1, a,b);
        return;
    }
}
// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
    memset(memo, -1, sizeof(memo));
    solve(0,0,a,b);
    getAns(0,0,a,b);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
