// https://www.hackerrank.com/challenges/contacts/problem
#include <bits/stdc++.h>

using namespace std;
const int ALPHA = 26;
struct Trie{
    Trie *child[ALPHA];
    int freq;
    Trie(){memset(child, 0,sizeof(child)); freq = 0;}
    void insert(string &s, int idx){
        freq++;        
        if(idx == (int)s.size()){return;}
        int letter = s[idx] - 'a';
        if(child[letter] == nullptr){child[letter] = new Trie();}
        child[letter]->insert(s, idx + 1);
    }
    void count(string &s, int idx, int &ans){
        if(idx == (int)s.size()){ans += freq; return;}
        int letter = s[idx] - 'a';
        if(child[letter] != nullptr){
            child[letter]->count(s, idx + 1, ans);
        }
    }
};
vector<int> contacts(vector<vector<string>> queries) {
    vector<int> ans;
    Trie *T = new Trie();
    for(auto query: queries){
        if(query[0] == "add"){
            T->insert(query[1], 0);
        }
        if(query[0] == "find"){
            int freq = 0;
            T->count(query[1], 0, freq);
            ans.push_back(freq);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
