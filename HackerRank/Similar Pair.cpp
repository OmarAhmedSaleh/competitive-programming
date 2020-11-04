#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the similarPair function below.
 */

vector <int> ft;
int LSOne(int S){
 return S & (-S);   
}
void initFenwickTree(int n) {
    ft.assign(n + 1, 0);
}

int rsq(int b) {    
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; 
}

int range(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
}
vector<vector<int>> tree;
vector <bool> seen;
void dfs(int idx , long long  &ans , int k){
    if(seen[idx]){return;}
    seen[idx] = true;
    int low = max(idx - k, 1);
    int high = min(idx + k , (int)tree.size());
    ans += range(low,high);
    adjust(idx,1);
    for(auto to: tree[idx]){
        if(!seen[to]){
            dfs(to, ans , k);
        }
    }
    adjust(idx,-1);
}

long long similarPair(int n, int k, vector<vector<int>> edges) {
    tree.clear();tree.resize(n + 1);
    seen.clear();seen.resize(n + 1, false);
    ft.clear();initFenwickTree(n + 1);
    vector<bool> isRoot(n + 1, true);
    for(int i = 0;i < (int)edges.size();i++){
        int p = edges[i][0], ch = edges[i][1];
        tree[p].push_back(ch);
        isRoot[ch] = false;
    }
    long long ans = 0;
    for(int i = 1;i <= n ; i++){
        if(isRoot[i]){
            dfs(i, ans, k);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> edges(n-1);
    for (int edges_row_itr = 0; edges_row_itr < n-1; edges_row_itr++) {
        edges[edges_row_itr].resize(2);

        for (int edges_column_itr = 0; edges_column_itr < 2; edges_column_itr++) {
            cin >> edges[edges_row_itr][edges_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = similarPair(n, k, edges);

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
