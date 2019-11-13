// https://www.hackerrank.com/challenges/magic-square-forming/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    vector < int > pre , origin;
    for(int i = 1; i < 10 ; i++){
        pre.push_back(i);
    }
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3; j++){
            origin.push_back(s[i][j]);
        }
    }
    int best = 9 * 9;
    do{
        vector < int > sum;
        int soFar = 0;
        for(int i = 0;i < 9; i++){
            if(i > 0 && i % 3 == 0){
                sum.push_back(soFar);
                soFar = 0;
            }
            soFar += pre[i];
        }
        sum.push_back(soFar);
        for(int i = 0;i < 3 ;i++){
            int idx = i;
             soFar = 0;
            while(idx < 9){
                soFar += pre[idx];
                idx += 3;
            }
            sum.push_back(soFar);
        }
        soFar = pre[0] + pre[4] + pre[8];
        sum.push_back(soFar);
        soFar = pre[2] + pre[4] + pre[6];
        sum.push_back(soFar);
        sort(sum.begin() , sum.end());
        if(sum.back() == sum[0]){
            int cost = 0;
            for(int i = 0;i < 9;i++){
                cost += abs(origin[i] - pre[i]);
            }
            best = min(best , cost);
        }
    }while(next_permutation(pre.begin(), pre.end()));
    return best;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
