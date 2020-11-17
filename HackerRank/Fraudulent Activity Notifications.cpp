
// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=sorting
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
const int NOT_FOUND = -1;
int find(vector<int> &freq, int x){
    for(int i = 0;i<(int)freq.size();i++){
        x -= freq[i];
        if(x <= 0){return i;}
    }
    return NOT_FOUND;
}
int activityNotifications(vector<int> expenditure, int d) {
    int n= (int)expenditure.size();
    int ans = 0;
    vector<int>cnt(222,0);
    for(int i = 0;i < n;i++){
        int m1 = 0, m2 = 0;
        if(i + 1 > d){
            m1 = find(cnt, (d + 1) / 2);
            if(d & 1){
                m1 *= 2;
            }else{
                m2 = find(cnt, d / 2 + 1);
            }
            if(m1 + m2 <= expenditure[i]){ans++;}
            cnt[expenditure[i - d]]--;
        }
        cnt[expenditure[i]]++;
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

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
