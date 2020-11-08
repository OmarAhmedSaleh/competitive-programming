// https://www.hackerrank.com/challenges/synchronous-shopping/problem?isFullScreen=false

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shop' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. STRING_ARRAY centers
 *  4. 2D_INTEGER_ARRAY roads
 */
struct state{
    int cat, center, collected;
    state(int _cat, int _center, int _collected){
        cat = _cat;
        center = _center;
        collected = _collected;
    }
};
int shop(int n, int k, vector<string> centers, vector<vector<int>> roads) {
    for(int i = 0;i < (int)centers.size();i++){
        cout << centers[i] << endl;
    }
    const int oo = 1e9;
    int MASK = 1 << k;
    int time[n][MASK][3];
    for(int i = 0; i < n ; i++){
        for(int j = 0;j < 1 << k  ;j++){
            for(int cat = 0; cat < 3; cat++){
                time[i][j][cat] = oo;
            }
        }
    }
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0;i < (int)roads.size();i++){
        int u = roads[i][0] , v = roads[i][1], w = roads[i][2];
        u--; v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
    int bits[n];
    memset(bits,0,sizeof(bits));
    for(int i = 0;i < (int)centers.size();i++){
        vector<int> all;
        int number = 0;
        for(int j = 0;j <= (int)centers[i].size(); j++){
            if(j == (int)centers[i].size() || centers[i][j] == ' '){
                all.push_back(number);
                number = 0;
                continue;
            }
            number *= 10; number += centers[i][j] - '0';
        }
        for(int j = 1 ; j < (int)all.size(); j++){
            bits[i]  |= (1 << (all[j] - 1));
        }
    }
    time[0][bits[0]][0] = time[0][bits[0]][1] = 0;
    queue<state> q;
    q.push(state(0,0,bits[0]));
    q.push(state(1,0,bits[0]));
    while(!q.empty()){
        state s = q.front();
        q.pop();
        for(int i =0;i < g[s.center].size(); i++){
            int to = g[s.center][i].first;
            int c = g[s.center][i].second;
            if(time[s.center][s.collected][s.cat] + c < time[to][s.collected | bits[to]][s.cat]){
                time[to][s.collected | bits[to]][s.cat] = time[s.center][s.collected][s.cat] + c;
                q.push(state(s.cat, to, s.collected | bits[to]));
            }
        }
    }
    for(int i = 0;i < MASK ;i++){
        for(int j = 0;j < MASK; j++){
            time[n - 1][i | j][2] = min(time[n - 1][i | j][2], max(time[n - 1][i][0], time[n - 1][j][1]));
        }
    }  
    
    return time[n - 1][MASK - 1][2];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<string> centers(n);

    for (int i = 0; i < n; i++) {
        string centers_item;
        getline(cin, centers_item);

        centers[i] = centers_item;
    }

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int res = shop(n, k, centers, roads);

    fout << res << "\n";

    fout.close();

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
