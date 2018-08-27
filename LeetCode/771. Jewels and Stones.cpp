class Solution {
public:
    int numJewelsInStones(string J, string S) {
    map< char , bool > mp;
        int sz = (int)J.size();
        for(int i=0;i<sz;i++){
            mp[J[i]] = 1;
        }
        int ret = 0;
        for(int i=0;i<(int)S.size();i++){
            ret+=mp.count(S[i]);
        }
        return ret;
    }
};
