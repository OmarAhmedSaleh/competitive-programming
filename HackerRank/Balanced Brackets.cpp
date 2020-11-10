// https://www.hackerrank.com/challenges/balanced-brackets/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
bool match(char op, char cl){
    return (op == '(' && cl == ')') || (op == '[' && cl == ']') || (op == '{' && cl == '}');
}
string isBalanced(string s) {
    vector<char>st;
    for(int i = 0;i < (int)s.size();i++){
        if((int)st.size() > 0 && match(st.back(), s[i])){
            st.pop_back();
        }else{
            st.push_back(s[i]);
        }
    }
    return (int)st.size() == 0 ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
