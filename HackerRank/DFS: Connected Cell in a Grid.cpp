// https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
#include <bits/stdc++.h>

using namespace std;

// Complete the maxRegion function below
int dx[8] = {1,1,-1,-1,0,0,1,-1};
int dy[8] = {-1,1,1,-1,1,-1,0,0};

void dfs(int i, int j, vector<vector<int>> &grid, int &cc){
    if(grid[i][j]==0){return;}
    cc++;
    grid[i][j] = 0;
    for(int dir = 0; dir < 8;dir++){
        int x = i + dx[dir];
        int y = j + dy[dir];
        if(x > -1 && y > -1 && x < grid.size() && y < grid.back().size()){
            dfs(x,y,grid,cc);
        }
    }
}
int maxRegion(vector<vector<int>> grid) {
    int ans = 0;
    for(int i = 0;i < grid.size();i++){
        for(int j = 0;j < grid.back().size();j++){
            if(grid[i][j]){
                int cc = 0;
                dfs(i,j,grid,cc);
                ans = max(ans,cc);
            }
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

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
