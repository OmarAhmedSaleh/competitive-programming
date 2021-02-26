class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int popped_it = 0;
        for(int i = 0;i < (int)pushed.size();i++){
            st.push_back(pushed[i]); 
            while(st.size() > 0 && popped_it < (int)popped.size() && st.back() == popped[popped_it]){st.pop_back(); popped_it++;}
        }
        return (int)st.size() == 0 && popped_it == popped.size();
    }
};
