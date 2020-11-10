// https://www.hackerrank.com/challenges/components-in-graph/problem
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the componentsInGraph function below.
 */
 vector<vector<int>> graph;
 vector<bool> seen;
 void dfs(int idx, int &count){
     if(seen[idx]){return;}
     seen[idx] = true;
     count++;
     for(auto to: graph[idx]){
         if(!seen[to]){dfs(to, count);}
     }
 }
vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = (int)gb.size();
    graph.clear(); graph.resize(2 * n); 
    seen.clear(); seen.resize(2 * n, false);
    for(int i = 0;i < (int)gb.size() ;i++){
        graph[gb[i][0] - 1].push_back(gb[i][1] - 1);
        graph[gb[i][1] - 1].push_back(gb[i][0] - 1);  
    }
    vector<int> ans(2, 2 * n);
    ans[1] = 0;
    for(int i = 0; i < 2 * n;i++){
        int count = 0;
        if((int)graph[i].size() > 0 && !seen[i]){
            dfs(i, count);
            ans[0] = min(ans[0], count);
            ans[1] = max(ans[1], count);    
        }
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> gb(n);
    for (int gb_row_itr = 0; gb_row_itr < n; gb_row_itr++) {
        gb[gb_row_itr].resize(2);

        for (int gb_column_itr = 0; gb_column_itr < 2; gb_column_itr++) {
            cin >> gb[gb_row_itr][gb_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = componentsInGraph(gb);

    for (int SPACE_itr = 0; SPACE_itr < result.size(); SPACE_itr++) {
        fout << result[SPACE_itr];

        if (SPACE_itr != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
