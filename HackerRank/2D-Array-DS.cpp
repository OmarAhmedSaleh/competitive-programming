#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int mx = -1e9;
    int sum = 0;
    for(int i = 1 ; i < 5 ; i++){
        for(int j = 1 ; j < 5 ; j++){
            sum = arr[i][j];
            for(int k = -1 ; k < 2 ; k++){
                sum += arr[i - 1][j + k];
                sum += arr[i + 1][j + k];
            }
            mx = max(mx , sum);
        }
    }
    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
