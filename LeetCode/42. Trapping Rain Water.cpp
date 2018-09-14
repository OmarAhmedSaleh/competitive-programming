class Solution {
public:
    int trap(vector<int>& height) {
        int sz = (int)height.size();
        if(sz < 1){
            return 0;
        }
        vector<int> r(sz);
        vector<int> l(sz);
        l[0]  =  0 ;
        int ret = 0;
        r[sz-1] = 0;
        for(int i = 1 ; i < sz; i++){
            l[i] = max(l[i-1],height[i-1]);
        }
        for(int i = sz-2; i > -1 ; i--){
            r[i] = max(r[i+1],height[i+1]);
        }
        for(int i = 0; i < sz ; i++){
            ret += max(min(l[i],r[i])-height[i],0);
        }
        return ret;
    }
};
