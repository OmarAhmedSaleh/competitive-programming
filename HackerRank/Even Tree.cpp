#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the evenForest function below.
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    vector < vector < int > > graph(t_nodes);
    for(int i = 0 ;i < t_edges ; i++){
        graph[t_from[i] - 1].push_back(t_to[i] - 1);
        graph[t_to[i] - 1].push_back(t_from[i] - 1);
    }
    vector < int > cnt(t_nodes , 1);
    vector < pair < int , int > > st; 
    st.push_back({0 , 0});
    vector < bool > seen(t_nodes , false);
    vector < int > last(t_nodes , -1);
    int ans = 0;
    while(!st.empty()){
        int node = st.back().first;
        int it = st.back().second;
        st.pop_back();
        seen[node] = true;
        int sz = (int)graph[node].size();
        if(last[node] != -1){
            if(cnt[last[node]] > 0 && cnt[last[node]] % 2 == 0){
                ans++;
            }else{
                cnt[node] += cnt[last[node]];
            }
        }
        while(it < sz){
            if(!seen[graph[node][it]]){
                last[node] = graph[node][it];
                st.push_back(make_pair(node , it + 1)); 
                st.push_back(make_pair(graph[node][it] , 0));
                break;  
            }
            it++;
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_nodes_edges_temp;
    getline(cin, t_nodes_edges_temp);

    vector<string> t_nodes_edges = split(rtrim(t_nodes_edges_temp));

    int t_nodes = stoi(t_nodes_edges[0]);
    int t_edges = stoi(t_nodes_edges[1]);

    vector<int> t_from(t_edges);
    vector<int> t_to(t_edges);

    for (int i = 0; i < t_edges; i++) {
        string t_from_to_temp;
        getline(cin, t_from_to_temp);

        vector<string> t_from_to = split(rtrim(t_from_to_temp));

        int t_from_temp = stoi(t_from_to[0]);
        int t_to_temp = stoi(t_from_to[1]);

        t_from[i] = t_from_temp;
        t_to[i] = t_to_temp;
    }

    int res = evenForest(t_nodes, t_edges, t_from, t_to);

    fout << res << "\n";

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
