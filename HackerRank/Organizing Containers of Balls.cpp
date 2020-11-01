// https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    bool possible = true;
    map < int ,int > mp;
    int n = (int)container.size();
    for(int i = 0;i < n;i++){
        int containerCapacity = 0;
        for(int j = 0;j < n ;j++){
            containerCapacity += container[i][j];
        }
        mp[containerCapacity]++;
    }
    for(int i = 0;possible && i < n;i++){
        int totalBallsForIColor = 0;
        for(int j = 0;j < n ;j++){
            totalBallsForIColor += container[j][i];
        }
        if(!mp.count(totalBallsForIColor) || mp[totalBallsForIColor] == 0){
            possible = false;
            break;
        }
        mp[totalBallsForIColor]--;
    }
    return possible ? "Possible" : "Impossible";

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

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
