class Solution {
public:
    vector<int> partitionLabels(string S) {
        bool firstTime[('z'-'a')+1];
        int cnt[('z'-'a')+1];
        for(int i=0;i<('z'-'a')+1;i++){
         cnt[i]=0;firstTime[i] = true;   
        }
        int sz = (int)S.size();
        vector<int>ret;
        for(int i=0;i<sz;i++){
            cnt[S[i]-'a']++;
        }
        int tot = 0;
        int st = 0;
        for(int i=0;i<sz;i++){
            if(firstTime[S[i]-'a']){
                firstTime[S[i]-'a']=0;
                if(!tot){st = i;}
                tot+=cnt[S[i]-'a']; 
            }
            tot--;
            if(!tot){
                ret.push_back(i-st+1);
            }
        }
        return ret;
    }
};
