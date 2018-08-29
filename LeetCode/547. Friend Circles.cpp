
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = (int)M.size();
        vector<bool> seen(n,0);
        vector<pair<int,int>>dfs;
        int ret = 0;
        for(int i=0;i<n;i++){
            if(!seen[i]){
                ret++;
            }
            dfs.push_back(make_pair(i,0));
            while((int)dfs.size()!=0){
                int idx = dfs.back().first;
                int it = dfs.back().second;
                seen[idx] = 1;
                dfs.pop_back();
                while(it<n){
                    if(M[idx][it]==1 &&!seen[it]){
                        dfs.push_back(make_pair(idx,it));
                        dfs.push_back(make_pair(it,0));
                        break;
                    }
                 it++;   
                }
            }
            
        }
        return ret;
    }
};
