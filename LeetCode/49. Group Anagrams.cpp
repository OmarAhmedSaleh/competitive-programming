class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        vector<int> cnt(27,0);
        int sz = (int)strs.size();
        for(int i=0;i<sz;i++){
            int len = (int)strs[i].size();
            for(int j=0;j<27;j++){
                cnt[j] = 0 ;
            }
            for(int j=0;j<len;j++){
                cnt[strs[i][j]-'a']++;
            }
            mp[cnt].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for(auto v:mp){
            ret.push_back(v.second);
        }
        return ret;
    }
};
