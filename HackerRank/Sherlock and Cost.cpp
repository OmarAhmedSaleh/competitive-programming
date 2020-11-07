// https://www.hackerrank.com/challenges/sherlock-and-cost/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int N = 1e5 + 1;
int memo[N][2];

int solve(int idx, int prev, vector<int> &B){
    if(idx == (int)B.size()){return 0;}
    if(memo[idx][prev] != -1){return memo[idx][prev];}
    int last = prev == 1 ? B[idx - 1] : 1;
    int ans = solve(idx + 1, 0, B) + abs(1 - last);
    ans = max(ans, solve(idx + 1, 1, B) + abs(B[idx] - last));
    return memo[idx][prev] = ans;
}
// Complete the cost function below.
int cost(vector<int> B) {
    memset(memo, -1, sizeof(memo));
    return max(solve(1, 1, B), solve(1, 0, B));
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string B_temp_temp;
        getline(cin, B_temp_temp);

        vector<string> B_temp = split_string(B_temp_temp);

        vector<int> B(n);

        for (int i = 0; i < n; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        int result = cost(B);

        fout << result << "\n";
    }

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
