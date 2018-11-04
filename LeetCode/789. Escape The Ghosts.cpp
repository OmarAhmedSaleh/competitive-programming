class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int mn = 2e9;
        for(int i = 0 ; i < (int)ghosts.size();i++){
            mn = min(mn,abs(ghosts[i][0] - target[0])+abs(ghosts[i][1] - target[1]));
        }
        return mn > (abs(target[0]) + abs(target[1]));
    }
};
