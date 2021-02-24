class Solution {
public:
    int scoreOfParentheses(string S) {
        int sz = (int)S.size(), ans = 0;
        vector<int> st, cnt(sz, 0);
        for(int i = 0;i < sz;i++){
            if(S[i] == '('){st.push_back(i); continue;}
            int idx = st.back(); st.pop_back();
            int sc = cnt[idx] > 0 ? cnt[idx] * 2 : 1;
            if(st.size() > 0){
                cnt[st.back()] += sc;
            }else{
                ans += sc;
            }
        }
        return ans;
    }
};
