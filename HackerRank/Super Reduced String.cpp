#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string emp = "Empty String";
    string ans = "";
    vector<char> st;
    for(int i = 0;i < (int)s.size();i++){
        if(st.empty() || (st.size() > 0 && st.back() != s[i])){
            st.push_back(s[i]);
        }else{
            st.pop_back();
        }
    }
    if((int)st.size() == 0){
        return emp;
    }
    for(int i =0;i < (int)st.size();i++){
        ans += st[i];
    } 
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
