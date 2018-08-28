class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = (int)temperatures.size();
        vector<int> ret(sz,sz);
        vector<int> lastAp(101,sz);
        for(int i=sz-1;i>-1;i--){
            lastAp[temperatures[i]] = i;
            for(int j=temperatures[i]+1;j<101;j++){
                if(lastAp[j]==sz){
                    continue;
                }
                ret[i]=min(ret[i],lastAp[j]-i);
            }
        }
        for(int i=0;i<sz;i++){
            ret[i] = ret[i]==sz ? 0:ret[i];
        }
     return ret;   
    }
};
