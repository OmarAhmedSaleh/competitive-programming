// https://www.hackerrank.com/challenges/the-quickest-way-up/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    const int MAX_DISTANCE = 111;
    const int CELLS = 101;  

    vector < int > laddersMap(CELLS, -1);
    vector < int > snakesMap(CELLS, -1);
    for(auto l : ladders){
        laddersMap[l[0]] = l[1];
    }
    for(auto s : snakes){
        snakesMap[s[0]] = s[1];
    }
    vector< int > dis(CELLS, MAX_DISTANCE);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        int to = -1;
        if(laddersMap[current] != -1){
             to = laddersMap[current];
             if(to < CELLS && dis[to] > dis[current]){
                    dis[to] = dis[current];
                    q.push(to);
                }
        }else{
            if(snakesMap[current] != -1){
                to = snakesMap[current];
                if(to < CELLS && dis[to] > dis[current]){
                    dis[to] = dis[current];
                    q.push(to);
                }
            }else{
                for(int i = 1;i < 7;i++){
                    to = current + i;
                    if(to < CELLS && dis[to] > dis[current] + 1){
                        dis[to] = dis[current] + 1;
                        q.push(to);
                    }
                }
            }
            
        }
    }
    return dis[100] != MAX_DISTANCE ? dis[100] : -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
