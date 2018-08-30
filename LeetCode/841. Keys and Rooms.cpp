class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = (int)rooms.size();
        vector<bool> seen(sz);
        vector<pair<int,int>> dfs;
        dfs.push_back(make_pair(0,0));
        while((int)dfs.size()){
            int idx = dfs.back().first;
            int it = dfs.back().second;
            dfs.pop_back();
            seen[idx]= 1;
            while(it<(int)rooms[idx].size()){
                if(!seen[rooms[idx][it]]){
                    dfs.push_back(make_pair(idx,it+1));
                    dfs.push_back(make_pair(rooms[idx][it],0));
                    break;
                }
            it++;
            }            
        }
        for(int i=0;i<sz;i++){
            if(!seen[i]){return 0;}
        }
        return 1;
    }
};
