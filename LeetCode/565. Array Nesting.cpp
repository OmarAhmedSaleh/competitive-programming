class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int MAXN = (int)nums.size() + 1;
        int best = 0;
        vector <int>  inComponent(MAXN, -1), cSize(MAXN, 0);
        int connectedComponent = 0;
        for(int i = 0;i < (int)nums.size();i++){
            int currentIndex = i;
            connectedComponent++;
            while(inComponent[currentIndex] == -1){
                cSize[connectedComponent]++;
                inComponent[currentIndex] = connectedComponent;
                int next = nums[currentIndex];
                if(inComponent[next] != -1){
                    if(inComponent[next] != inComponent[currentIndex]){
                        cSize[connectedComponent] += cSize[inComponent[next]];
                    }
                    break;
                }
                currentIndex = next;
            }
            best = max(best, cSize[connectedComponent]);
        }
        return best;
    }
};
// 5 4 0 3 1 6 2
// 0 1 2 3 4 5 6
// 
