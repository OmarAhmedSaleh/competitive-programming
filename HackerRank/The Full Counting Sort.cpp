// https://www.hackerrank.com/challenges/countingsort4/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countSort function below.
int AtoI(string s){
    int n = 0;
    for(auto c : s){
        n *= 10;
        n += (c - '0');
    }
    return n;
}
void countSort(vector<vector<string>> arr) {
    vector<vector<string>> buckets(101);
    int sz = (int)arr.size();
    for(int i = 0;i < sz;i++){
        if(i < sz / 2){arr[i][1] = "-";}
        int x = AtoI(arr[i][0]);
        buckets[x].push_back(arr[i][1]);
    }
    for(int i = 0;i < 101;i++){
        for(int j = 0;j < buckets[i].size();j++){
            cout << buckets[i][j] << " ";
        }
    }
    cout << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
