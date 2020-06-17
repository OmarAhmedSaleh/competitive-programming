#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int oo = 1e9;
vector < long long > p;
vector <vector < int > > g;
int n , m , a , b , c;
void bfs(int st , vector < int > &dis){
    queue<int> q;
    dis[st] = 0;
    q.push(st);
    while(q.size() > 0){
        int f = q.front();
        q.pop();
        int to = -1;
        for(int i = 0;i < (int)g[f].size(); i++){
            to = g[f][i];
            if(dis[to] > dis[f] + 1){
                dis[to] = dis[f] + 1;
                q.push(to);
            }
        }
    }
}
long long go(){
    cin >> n >> m >> a >> b >> c;
    p = vector < long long >(m + 1 , 0);
    for(int i = 1;i <= m; i++){
        cin >> p[i];
    }
    p[0] = 0;
    sort(p.begin() , p.end());
    for(int i = 1;i <= m ;i++){
        p[i] += p[i - 1];
    }
    g = vector< vector< int > >(n);
    a--;b--;c--;
    for(int i = 0;i < m ;i++){
        int q , w;
        cin >> q >> w;
        q--;w--;
        g[q].push_back(w);
        g[w].push_back(q);
    }
    vector < int > da(n, oo) , db(n, oo) , dc(n, oo);  
    bfs(a , da);
    bfs(b  , db);
    bfs(c  , dc);
    if(a == b && a != c){
        return p[da[c]];
    }
    if(a == c && a != b){
        return p[da[b]] * 2;
    }
    if(c == b && a != b){
        return p[da[b]];
    }
    if(a == c && b == c){
        return 0;
    }
    long long ans = (long long) 1e18;
    for(int i = 0;i < n ; i++){
        if(da[i] + db[i] + dc[i] > m){continue;}
        ans = min(ans , p[da[i] + db[i] + dc[i]] + p[db[i]]);
    }  
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cout << go() << endl;
    }
    return 0;
}
