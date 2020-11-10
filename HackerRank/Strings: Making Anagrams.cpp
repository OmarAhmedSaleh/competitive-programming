// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
void addValue(string &s, int value, vector<int> &count){
    for(int i = 0;i < (int)s.size();i++){
        count[s[i] - 'a'] += value;
    }
}
int makeAnagram(string a, string b) {
    vector<int> count(26, 0);
    addValue(a, 1, count);
    addValue(b, -1, count);
    int ans = 0;
    for(int i = 0;i < 26; i++){
        ans += abs(count[i]);
    }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
