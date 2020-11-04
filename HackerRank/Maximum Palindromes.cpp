#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */
const int MOD = 1e9 + 7;
const int MAXSZ = 1e5 + 1;
vector<long long> fac, rFac;
int sz;
int cnt[MAXSZ][33];
long long power(long long xx, long long yy){
    if (yy == 0) return 1;
    if(yy & 1){
        return power(xx, yy - 1) * xx % MOD;
    }else{
        long long temp = power(xx, yy / 2);
        return temp * temp % MOD;
    }
}
void initialize(string s) {
    // This function is called once before all queries.
    sz = (int)s.size();
    fac.resize(sz + 1);
    rFac.resize(sz + 1);
    
    fac[0] = 1;
    rFac[0] = 1;
    memset(cnt, 0 ,sizeof(cnt));
    for(int i = 1; i <= sz; i++){
        fac[i] = 1LL * i * fac[i - 1] % MOD;
        rFac[i] = power(fac[i], MOD - 2);
    }
    for(int i = 0;i <sz;i++){
        cnt[i][s[i] - 'a']++;
        if(i > 0){
            for(int j = 0;j < 26;j++){
                cnt[i][j] += cnt[i - 1][j];
            }
        }
    }
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.
    l--; r--;
    int freq[33];
    for(int i = 0;i < 33;i++){
        freq[i] = cnt[r][i];
    }
    if(l > 0){
        for(int i = 0;i < 33;i++){
            freq[i] -= cnt[l - 1][i];
        }
    }
    vector <int> p;
    int odds = 0;
    int mxPairs = 0;
    for(int i = 0;i < 33 ; i++){
        if(freq[i] % 2 != 0){odds++;}
        int d = freq[i] / 2;
        if(d > 0){
            mxPairs += d;
            p.push_back(d);
        }
    }    
    long long ans = fac[mxPairs];
    for(auto pr: p){
        ans = 1LL * ans * rFac[pr] % MOD;
    }
    odds = max(odds, 1);
    ans = 1LL * ans * odds % MOD;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
