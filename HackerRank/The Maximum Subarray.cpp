
// https://www.hackerrank.com/challenges/maxsubarray/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const int N = 1e5;
const int oo = 2e9;
int memo[N][2];
bool seen(int idx, int t){
    return memo[idx][t] != -oo;
}
int solve(int idx, int take, vector<int> &arr){
    if(idx == (int)arr.size()){
        return 0;
    }
    if(seen(idx,take)){return memo[idx][take];}
    int ans = max(solve(idx + 1, 0, arr), solve(idx + 1, 1, arr)) + (take * arr[idx]);
    return memo[idx][take] = ans;    
}


// Complete the maxSubarray function below.
vector<int> maxSubarray(vector<int> arr) {
    vector<int> acc((int)arr.size(), 0);
    vector<int> ans(2, -oo);    
    for(int i = 0;i < (int)arr.size();i++){
        acc[i] = arr[i];
        ans[0] = max(ans[0], arr[i]);
        ans[1] = max(ans[1], arr[i]);
        memo[i][0] = memo[i][1] = -oo;
    }
     ans[1] = solve(0, 1, arr);    
    for(int i = 1;i < (int)arr.size();i++){
        acc[i] = max(arr[i] + acc[i - 1], arr[i]);
        ans[0] = max(acc[i], ans[0]);
        ans[1] = max(ans[1], solve(i, 1, arr));
    }
    return ans;
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

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        vector<int> result = maxSubarray(arr);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
