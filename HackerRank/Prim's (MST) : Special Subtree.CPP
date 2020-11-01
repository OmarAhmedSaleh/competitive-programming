#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the prims function below.
void process(int vtx, vector <bool> &taken, priority_queue<pair<int,int>> &pq, vector<vector<pair<int,int>>> &graph){
    taken[vtx] = true;
    for(auto edge : graph[vtx]){
        if(!taken[edge.first]){
            pq.push({-edge.second, -edge.first});
        }
    }
    
}
int prims(int n, vector<vector<int>> edges, int start) {
    vector<vector<pair<int,int>>> graph(n);
    for(int i = 0;i <(int)edges.size();i++){
        graph[edges[i][0] - 1].push_back({edges[i][1] - 1,edges[i][2]});
        graph[edges[i][1] - 1].push_back({edges[i][0] - 1,edges[i][2]});
    }
    priority_queue<pair<int,int>> pq;
    vector<bool> taken(n, false);
    int mst_cost = 0;
    process(start - 1, taken, pq, graph);
    while(!pq.empty()){
        pair<int,int> front = pq.top(); pq.pop();
        int u = -front.second; int w = -front.first;
        if(!taken[u]){
            mst_cost += w; process(u, taken, pq, graph);
        }
    }
    return mst_cost;
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

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

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
