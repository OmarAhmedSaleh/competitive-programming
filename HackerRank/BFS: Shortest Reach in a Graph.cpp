#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    public:
        vector<vector<int>> graph;    
        Graph(int n) {
            graph.resize(n);
        }
    
        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
            
        }
    
        vector<int> shortest_reach(int start) {
            queue<int> q;
            vector<int> dis(graph.size() , -1);
            q.push(start);
            dis[start] = 0;
            while(!q.empty()){
                int f = q.front();
                q.pop();
                for(auto to: graph[f]){
                    if(dis[to] == -1){dis[to] = dis[f] + 6; q.push(to);}
                }
            }
            return dis;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
