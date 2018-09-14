class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        int sz = (int)wordlist.size();
        if((int)beginWord.size() != (int)endWord.size()){
            return 0;
        }
        int df = 0;
        for(int i = 0 ; i < (int)beginWord.size() ; i++ ){
            df+=beginWord[i]!=endWord[i];
        }
        if(df>sz){
            return 0;
        }
        const int oo = 2e9;
        const int MAX = (int)sz+1;
        vector<int> dis(MAX,oo);
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,0));
        dis[0] = 0;
        string s_f = "";
        int idx_f = 0;

        while((int)q.size()){
            s_f = q.front().first;
            idx_f = q.front().second;
           // cout << s_f << " " << dis[idx_f] << endl;
            q.pop();
            df = 0 ;
            int len = (int)s_f.size();
            for(int i  = 0 ; i<sz ; i++){
                if(len!=(int)wordlist[i].size()){
                    continue;
                }
                df = 0;
                for(int j = 0 ; j < len ; j++){
                    df+=s_f[j]!=wordlist[i][j];
                }
                if( (df == 1) &&( dis[i+1] == oo || dis[i+1] > dis[idx_f] + 1 )){
                    dis[i+1] = dis[idx_f] + 1;
                    q.push(make_pair(wordlist[i],i+1));
                }
            }
        }
        int eWord_idx =-1;
        for(int i = 0 ; i<sz ; i++){
            if(wordlist[i]==endWord){
                eWord_idx = i+1;
            }
        }
        //cout<< eWord_idx <<endl;
        if(eWord_idx == -1 || dis[eWord_idx]==oo){
            return 0;
        }
        return dis[eWord_idx]+1;
    }
};
