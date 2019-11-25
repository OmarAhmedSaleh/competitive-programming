#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int solve(string &s1 , string &s2 , int i , int j , vector < vector < int > > &memo){
    if(i == (int)s1.size() || j == (int)s2.size()){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = solve(s1 , s2 , i + 1 , j + 1 , memo);
    ans = max(solve(s1 , s2 , i , j + 1 , memo) , ans);
    ans = max(solve(s1 , s2 , i + 1, j , memo) , ans);
    if(s1[i] == s2[j]){
        ans = max(ans , solve(s1 , s2 , i + 1 , j + 1 , memo) + 1);
    }
    return memo[i][j] = ans;
}
int commonChild(string s1, string s2) {
    vector < vector < int > > memo((int)s1.size() , vector < int > ((int)s2.size() , -1));
    return solve(s1 , s2 , 0 , 0 , memo);
 of a string .
The second line contains a string  of length .

Constraints


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
