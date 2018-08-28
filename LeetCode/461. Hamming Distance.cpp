class Solution {
public:
    int hammingDistance(int x, int y) {
        long long xr = (long long)x^y;
        int ret = 0;
        while(xr){
            ret+=xr&1;
            xr>>=1;
        }
        return ret;
    }
};
