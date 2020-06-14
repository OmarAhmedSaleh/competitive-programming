#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    const int oo = 1e9;
    vector < int > v(n) , dis(n , oo);
    for(int i = 0;i < n;i++){
        cin >> v[i];
    }
    vector < vector < int > > g(n);
    queue<int> q;
    for(int i = 0;i < n;i++){
        int next = i + v[i];
        if(next < n){
            g[next].push_back(i);
            if((v[i] + v[next]) & 1){
                dis[i] = 1;
                q.push(i);
            }
        }
        int pre = i - v[i];
        if(pre > -1){
            g[pre].push_back(i);
            if((v[i] + v[pre]) & 1){
                dis[i] = 1;
                q.push(i);
            }
        }
    }
    while(!q.empty()){
        int f = q.front();
        q.pop();
        int to = -1;
        for(int i = 0;i < (int)g[f].size();i++){
            to = g[f][i];
            if((v[to] + v[f]) % 2 == 0 && dis[to] > dis[f] + 1){
                dis[to] = dis[f] + 1;
                q.push(to);
            }
        }
    }
    for(int i = 0;i < n; i++){
        if(i){
            cout << " ";
        }
        dis[i] = dis[i] == oo ? -1 : dis[i];
        cout << dis[i];
    }
    cout << endl;

    return 0;
}
