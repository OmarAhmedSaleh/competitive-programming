#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    vector<vector<int>> graph(n);
    for(int i = 0;i < cities.size(); i++){
        int a = cities[i][0] - 1;
        int b = cities[i][1] - 1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector < int > cSize(n, 0);
    vector <bool> seen(n, false);
    queue <int> q;
    int cc = 0;
    long long ans = 0;
    for(int i = 0;i < n ;i++){
        if(!seen[i]){
            q.push(i);
            seen[i] = true;
            while(q.size() > 0){
                int f = q.front();
                cSize[cc]++;
                q.pop();
                for(auto to : graph[f]){
                    if(!seen[to]){
                        q.push(to);
                        seen[to] = true;
                    }
                }
            }
            if(cSize[cc] == 1){
                ans += c_lib;
            }else{
                ans += min(1LL * cSize[cc] * c_lib, 1LL * (cSize[cc] - 1) * c_road + c_lib);
            }
            cc++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

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
