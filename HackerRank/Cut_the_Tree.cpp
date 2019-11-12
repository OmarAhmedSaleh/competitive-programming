#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    queue < int > q;
    int n = (int)data.size();
    vector < int > in_deg(n , 0);
    vector < vector < int > > graph(n);
    for(int i = 0 ; i < n - 1; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        in_deg[v - 1]++;
        in_deg[u - 1]++;
        graph[v - 1].push_back(u - 1);
        graph[u - 1].push_back(v - 1); 
    }
    int total = 0;
    for(int i = 0;i < n ; i++){
        if(in_deg[i] == 1){
            q.push(i);
        }
        total += data[i];
    }
    int best = total;
    while(!q.empty()){
        int idx = q.front();
        q.pop();
        best = min(best , abs(total - (2 * data[idx])));
        int to = -1;
        for(int i = 0; i < (int)graph[idx].size(); i++){
            to = graph[idx][i];
            if(in_deg[to] != 0){
                in_deg[to]--;
                in_deg[idx] = 0;
                data[to] += data[idx];
                if(in_deg[to] == 1){
                    q.push(to);
                }
                break;
            }
        }
    }
    return best;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
    }

    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        edges[i].resize(2);

        string edges_row_temp_temp;
        getline(cin, edges_row_temp_temp);

        vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int edges_row_item = stoi(edges_row_temp[j]);

            edges[i][j] = edges_row_item;
        }
    }

    int result = cutTheTree(data, edges);

    fout << result << "\n";

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
