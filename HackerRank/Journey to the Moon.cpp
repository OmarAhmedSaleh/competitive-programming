// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
vector<int> inComponent;
vector<int> numberOfNodesInComponent;
vector<vector<int>> graph;
void dfs(int root, int component){
    if(inComponent[root] != -1){
        return ;
    }
    numberOfNodesInComponent[component]++;
    inComponent[root] = component;
    for(auto to: graph[root]){
        if(inComponent[to] == -1){dfs(to, component);}
    }
}
void reset(int n){
    inComponent.clear();
    graph.clear();
    numberOfNodesInComponent.clear();
    inComponent.resize(n + 1, -1);
    graph.resize(n + 1, vector <int>());
    numberOfNodesInComponent.resize(n + 1, 0);
}
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    reset(n);
   
   // graph construction 
    for(auto p : astronaut){
        int a = p[0], b = p[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // mark each node which component it belongs to
    int cc = 0;
    for(int i = 0;i < n;i++){
        if(inComponent[i] == -1){
            dfs(i, cc);
            cc++;
        }
    }
    long long sum = 0, result = 0;
    for(int i = 0;i < cc;i++){
        result +=  1LL * sum * numberOfNodesInComponent[i];
        sum += numberOfNodesInComponent[i];
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

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
