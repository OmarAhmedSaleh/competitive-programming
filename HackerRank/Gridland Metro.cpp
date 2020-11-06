// https://www.hackerrank.com/challenges/gridland-metro/problem?isFullScreen=true
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridlandMetro function below.
long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    long long ans = 1LL * n * m;
    map<int,vector<pair<int,int>>> mp;
    vector<int> distinctRows;
    for(int i = 0;i < (int)track.size();i++){
        int r = track[i][0] - 1;
        int c1 = track[i][1] - 1;
        int c2 = track[i][2] - 1;
        if(!mp.count(r)){distinctRows.push_back(r);}
        auto v = mp[r];
        v.push_back({c1,c2});
        mp[r] = v;
    }
    for(int i = 0;i < (int)distinctRows.size();i++){
        int r = distinctRows[i];
        auto v = mp[r];
        sort(v.begin(), v.end());
        int st = 0, ed = 0;
        while(st < v.size()){
            ed = st;
            int next = ed + 1;            
            while(next < v.size() && v[next].first >= v[st].first && v[next].first <= v[st].second){
                if(v[st].second  < v[next].second){v[st].second = v[next].second;}
                next++;                
            }
            ans -= v[st].second - v[st].first + 1;
            st = next;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector<vector<int>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = gridlandMetro(n, m, k, track);

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
