// Dynamic Programming 
class Solution {
public:
    vector< vector<int> > memo;
    void setMemo(int n){
        memo.resize(n,vector<int>(3,-1));
    }
    int solve(int idx, int last ,vector<int> & p){
        if(idx == (int)p.size()){
            return 0;
        }
        if(memo[idx][last]!=-1){
            return memo[idx][last];
        }
        int ans = 0;
        // 0 can buy , 1 can sell , 2 must cooldown
        if(last == 0){
            ans = max(ans,solve(idx+1,1,p)-p[idx]);
            ans = max(ans,solve(idx+1,last,p));
        }
        if(last==1){
            ans = max(ans,solve(idx+1,2,p)+p[idx]);
            ans = max(ans,solve(idx+1,last,p));
        }
        if(last == 2){
          ans = solve(idx+1,0,p);
        }
        return memo[idx][last] = ans;

    }
    int maxProfit(vector<int>& prices) {
        int sz = (int)prices.size();
        setMemo(sz);
        return solve(0,0,prices);
        
    }
};
