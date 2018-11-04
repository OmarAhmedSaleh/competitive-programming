class Solution {
public:
    int n , m;
    vector< vector<int> > memo;
    void setMemo(){
        memo.resize(n,vector<int>(m,-1));
    }
    int solve(int i , int j , string &s, string &t){
        if(i == n && j == m){
            return 0;
        }
        if(i == n || j == m){
            return (n-i) + (m-j);
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        int ans = solve(i+1,j+1,s,t)+2;
        if(s[i]==t[j]){
            ans = min(ans,solve(i+1,j+1,s,t));
        }
        ans = min(ans,solve(i+1,j,s,t)+1);
        ans = min(ans,solve(i,j+1,s,t)+1);
        return memo[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        n = (int)word1.size();
        m = (int)word2.size();
        setMemo();
        return solve(0,0,word1,word2);
    }
};
