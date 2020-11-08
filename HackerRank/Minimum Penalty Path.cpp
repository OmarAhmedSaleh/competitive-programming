#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulPath function below.
int beautifulPath(vector<vector<int>> edges, int A, int B) {
    int n = 0;
    for(int i = 0;i < (int)edges.size();i++){n = max(n, max(edges[i][0], edges[i][1]));}
    bool seen[n][(1 << 11)];
    memset(seen, 0,sizeof(seen));
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0;i <(int)edges.size();i++){
        g[edges[i][0] - 1].push_back({edges[i][1] - 1, edges[i][2]});
        g[edges[i][1] - 1].push_back({edges[i][0] - 1, edges[i][2]});
    }
    A--;B--;
    queue<pair<int,int>> q;
    q.push({A, 0});
    seen[A][0] = true;
    int ans = 1e9;
    while(!q.empty()){
        int idx = q.front().first, c = q.front().second;
        q.pop();
        if(idx == B){ans = min(ans, c); continue;}
        for(auto p: g[idx]){
            int newc = c | p.second;
            if(!seen[p.first][newc]){seen[p.first][newc] = true; q.push({p.first, newc});}
        }
    }
    return ans == 1e9 ? -1 : ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string AB_temp;
    getline(cin, AB_temp);

    vector<string> AB = split_string(AB_temp);

    int A = stoi(AB[0]);

    int B = stoi(AB[1]);

    int result = beautifulPath(edges, A, B);

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
