class Solution {
public:
    void dfs(int idx, vector<vector<int>> &rooms, vector<bool> &visited){
        if(visited[idx]){return ;}
        visited[idx] = true;
        for(int to: rooms[idx]){
            if(!visited[to]){dfs(to, rooms, visited);}
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size() + 1 , false);
        dfs(0, rooms, visited);
        for(int i = 0; i < rooms.size();i++){
            if(!visited[i]){return false;}
        }
        return true;
    }
};
