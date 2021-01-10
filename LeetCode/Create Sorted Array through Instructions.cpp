class Solution {
public:
    vector <int> ft;
    int LSOne(int S){
     return S & (-S);   
    }
    void initFenwickTree(int n) {
        ft.assign(n + 1, 0);
    }

    int rsq(int b) {    
        int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
        return sum; 
    }

    int range(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void adjust(int k, int v) {
        for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
    }
    int createSortedArray(vector<int>& instructions) {
        int N = 1e5, n = instructions.size();
        const int MOD = 1e9 + 7;
        ft.clear();initFenwickTree(N + 1);
        long long ans = 0;
        for(int i = 0;i < n;i++){
            int l = instructions[i] == 1 ? 0: range(1 , instructions[i] - 1);
            int g = range(instructions[i] + 1, N);
            ans += min(l, g);
            if(ans > MOD){ans -= MOD;}
            adjust(instructions[i], 1);
        }
        return ans;
    }
};
