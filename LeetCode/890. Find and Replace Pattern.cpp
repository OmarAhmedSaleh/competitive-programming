class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        int per[2][27];
        int sz = (int)words.size();
        int n = (int)pattern.size();
        for(int i=0;i<sz;i++){
            if((int)words[i].size() !=n){continue;}
            memset(per,-1,sizeof(per));
            bool ok = 1;
            for(int j=0;j<n;j++){
                if(per[1][pattern[j]-'a']!=-1 && per[1][pattern[j]-'a']!=(words[i][j]-'a')){
                    ok = 0;
                    break;
                }
                if(per[0][words[i][j]-'a']!=-1 && per[0][words[i][j]-'a']!=(pattern[j]-'a')){
                    ok = 0;
                    break;
                }
                per[0][words[i][j]-'a']=pattern[j]-'a';
                per[1][pattern[j]-'a']=words[i][j]-'a';
            }
            if(ok){
                ret.push_back(words[i]);
            }
        }
        return ret;
    }
};
