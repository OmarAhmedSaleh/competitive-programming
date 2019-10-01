class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector < pair < char , int > > seq;
        for(int i = 0;i < (int)s.size() ; i++){
            if(!seq.empty() && seq.back().first == s[i]){
                seq.back().second++;
                if(seq.back().second == k){
                    seq.pop_back();
                }
            }else{
                seq.push_back({s[i] , 1});
            }
        }
        string ans = "";
        for(int i = 0;i < (int)seq.size() ; i++){
            int len = seq[i].second;
            while(len-->0){
                ans += seq[i].first;
            }
        }
        return ans;
    }
};
