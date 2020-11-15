https://www.hackerrank.com/challenges/down-to-zero-ii/copy-from/187975930

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the downToZero function below.
 */
const int oo = 1e7, N = 1e6;
int dis[N + 1];
int downToZero(int n) {
    memset(dis , -1,sizeof(dis));
    dis[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        if(f < 0){continue;}
        if(f == 0){break;}
        for(int i = 2; 1LL * i * i <= f; i++){
                int d = f / i;            
                if(f % i == 0 && d > 1){
                    int mx = max(i , d);
                if(dis[mx]==-1){dis[mx] = dis[f] + 1; q.push(mx);}        
                }
            }
        if(dis[f - 1]==-1){dis[f - 1] = dis[f] + 1; q.push(f - 1);}            
    }
    return dis[0];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = downToZero(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
