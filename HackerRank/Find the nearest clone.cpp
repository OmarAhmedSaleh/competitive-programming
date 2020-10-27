// https://www.hackerrank.com/challenges/find-the-nearest-clone/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
const int MAX_DISTANCE = 1e7;
 vector<vector<int>> graph;
 vector<bool>seen;

 int dfs(int idx, vector<long> &colors, int &val, int &ans){
     seen[idx] = true;
     int first = MAX_DISTANCE, second = MAX_DISTANCE;
     for(auto to : graph[idx]){
         if(!seen[to]){
             int d = dfs(to, colors, val, ans);
             if(d < first){
                 second = first;
                 first = d;
             }else{
                 second = min(second, d);
             }
         }
     }
     if(colors[idx] == val){
         ans = min(ans, first);
         return 1;
     }
     ans = min(ans, first + second);
     return min(first + 1, MAX_DISTANCE);

 }
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    graph.clear();
    seen.clear();
    seen.resize(graph_nodes);
    graph.resize(graph_nodes);
    for(int i = 0;i < (int)graph_from.size();i++){
        int u = graph_from[i] - 1;
        int v = graph_to[i] - 1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = MAX_DISTANCE;
    dfs(0, ids, val, ans);
    return ans == MAX_DISTANCE ? -1 : ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

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
