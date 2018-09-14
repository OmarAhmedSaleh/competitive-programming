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
        const int MAX = (int)sz+1;
        vector<int> dis(MAX,MAX);
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord,0));
        string s_f = "";
        int dis_f = 0;
        while((int)q.size()){
            s_f = q.front().first;
            dis_f = q.front().second;
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
                if( (df == 1) &&( dis[i] == MAX || dis[i] > dis_f + 1 )){
                    dis[i] = dis_f + 1;
                    q.push(make_pair(wordlist[i],dis[i]));
                }
            }
        }
        int eWord_idx =-1;
        for(int i = 0 ; i<sz ; i++){
            if(wordlist[i]==endWord){
                eWord_idx = i;
            }
        }
        if(eWord_idx == -1 || dis[eWord_idx]==MAX){
            return 0;
        }
        return dis[eWord_idx]+1;
    }
};
