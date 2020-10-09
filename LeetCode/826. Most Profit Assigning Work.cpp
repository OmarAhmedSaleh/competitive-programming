class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int MAX = 1e5;
        vector < int > best(MAX + 1 , 0);
        for(int i = 0;i < (int)difficulty.size(); i++){
            int diff = difficulty[i];
            best[diff] = max(best[diff], profit[i]);
        }
        for(int i = 1;i <= MAX;i++){
            best[i] = max(best[i], best[i - 1]);
        }
        int ans = 0;
        for(int i = 0;i < (int)worker.size(); i++){
            ans += best[worker[i]];
        }
        return ans;
    }
};
