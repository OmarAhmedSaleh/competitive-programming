class Solution {
public:
    bool queryString(string S, int N) {
        reverse(S.begin() , S.end());
        long long p = 1;
        int sz = (int)S.size();
        map < long long , int > mp;
        for(int i = 0; i < sz ; i++){
            long long cnt = 0;
            p = 1;
            for(int j = i;j < sz ; j++){
                if(p > N){
                    break;
                }
                if(S[j] == '1'){
                    cnt += p;
                }
                p *= 2;
                if(cnt > 0 && cnt <= N){
                    mp[cnt] = 1;
                } 
            }
        }
        return (int)mp.size() == N;
    }
};
