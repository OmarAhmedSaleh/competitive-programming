class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
      const int oo = 1e9;
      int rows = (int)matrix.size();
      int col = 0;
      if(rows > 0){
        col = (int)matrix.back().size();
      }
      vector < vector < int > > dis(rows , vector< int > (col , oo));
      queue < pair < int , int > > q;
      for(int i = 0;i < rows ;i++){
        for(int j = 0 ;j < col ; j++){
          if(matrix[i][j] == 0){
            dis[i][j] = 0;
            q.push({i , j});
          }
        }
      }
      int dx[] = {1 , -1 , 0 , 0};
      int dy[] = {0 , 0 , 1 , -1};
      while(!q.empty()){
        pair < int , int > xy = q.front();
        q.pop();
        for(int i = 0;i < 4; i++){
          int new_x = dx[i] + xy.first;
          int new_y = dy[i] + xy.second;
          if(new_x > -1 && new_x < rows && new_y > -1 && new_y < col && dis[new_x][new_y] > dis[xy.first][xy.second] + 1){
            dis[new_x][new_y] = dis[xy.first][xy.second] + 1;
            q.push({new_x , new_y});
          }
        }
      }
      return dis;
    }
};
