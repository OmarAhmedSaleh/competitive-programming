class Solution {
public:
    int dx[4] = {1,-1,0,0}; 
    int dy[4] = {0,0,1,-1};
    bool valid(int &x , int &y , int &n,int &m){
        return x > -1 && y > -1 && x < n && y < m;
    }
    struct cell{
        int x, y, c;
        cell(int xx , int yy ,int cc){
            x = xx;
            y = yy;
            c = cc;
        }
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> area;
        queue < cell > q;
        int r = (int)grid.size();
        int c =(int)grid.back().size();
        cell cl(0,0,0);
        for(int i = 0 ; i < r ;i++){
            for(int j = 0 ; j < c ; j++){
                if(grid[i][j]!=1){
                    continue;
                }
                q.push(cell(i,j,(int)area.size()));
                area.push_back(0);
                grid[i][j] = -1;
                while(!q.empty()){
                    cl.x = q.front().x;
                    cl.y = q.front().y;
                    cl.c = q.front().c;
                    q.pop();
                    area[cl.c]++;
                    for(int k = 0 ; k < 4; k++){
                        int nw_x = cl.x + dx[k];
                        int nw_y = cl.y + dy[k];
                        if(valid(nw_x,nw_y,r,c) && grid[nw_x][nw_y]==1){
                            q.push(cell(nw_x,nw_y,cl.c));
                            grid[nw_x][nw_y] = -1;
                        }
                    }                    
                }
            }
        }
        if(area.size()){
            sort(area.begin(),area.end());
            return area.back();
        }
        return 0;
    }
};
