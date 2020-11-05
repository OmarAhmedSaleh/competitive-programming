// https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
#include <bits/stdc++.h>

using namespace std;
int dis[25][25];
int bfs(int n, vector <int> &dx,vector<int>& dy){
    dis[0][0] = 0;    
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;  
        q.pop();
        for(int dir = 0; dir < 8; dir++){
            int xx = dx[dir] + x;
            int yy = dy[dir] + y;
            if(xx > -1 && yy > -1 && xx < n && yy < n && dis[xx][yy] > dis[x][y] + 1){
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx,yy});
            }
        }
    }
    return dis[n - 1][n - 1];
}
// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    const int MAXD = 1e5;
    vector<vector<int>>ans(n - 1, vector<int> (n - 1, -1));
    for(int a = 1; a < n ; a++){
        for(int b = 1 ;b < n; b++){
            for(int i = 0;i < n ; i++){
                for(int j = 0;j < n ;j++){
                    dis[i][j] = MAXD;
                }
            }
             vector<int> dx = {a, a, -a, -a, b, b, -b, -b};
             vector<int> dy = {b, -b, b, -b, a, -a, a, -a};        
             int result = bfs(n, dx, dy);    
             ans[a - 1][b - 1] = result != MAXD ? result : -1;       
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

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
