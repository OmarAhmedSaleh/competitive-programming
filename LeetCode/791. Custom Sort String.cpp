class Solution {
public:
    string customSortString(string S, string T) {
        vector < int > occ(26 , 0);
        int szT = (int)T.size();
        for(int i = 0;i <  szT;i++){
            occ[T[i] - 'a']++;
        }
        string ret = "";
        int szS = (int)S.size();
        for(int i = 0;i < szS ; i++){
            while(occ[S[i] - 'a'] > 0){
                occ[S[i] - 'a']--;
                ret += S[i];
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            while(occ[i] > 0){
                occ[i]--;
                ret += (char)'a' + i;
            }
        }
        return ret;
    }
};
