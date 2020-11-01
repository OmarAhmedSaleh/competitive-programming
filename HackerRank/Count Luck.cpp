#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k) {
    vector<vector<int>> g;
    const int oo = 1e9;
    int n = (int)matrix.size();
    int m = (int)matrix.back().size();
    g.resize(n, vector<int>(m, oo));
    queue<pair<int,int>>q;
    int eX = 0, eY = 0;
    for(int i = 0;i < n ; i++){
        for(int j = 0;j < m ;j++){
            if(matrix[i][j] == 'M'){
                q.push({i,j});
                g[i][j] = 0;
            }
            if(matrix[i][j] == '*'){
                eX = i; eY = j;
            }
        }
    }
    int dx[4] = {1, -1, 0 , 0};
    int dy[4] = {0, 0, 1 , -1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(g[x][y] > k){continue;}
        int validCells = 0;
        for(int i = 0;i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(newX > -1 && newY > -1 && newX < n && newY < m && matrix[newX][newY] != 'X' && g[newX][newY] == oo){
                validCells++;
            }
        }
        for(int i = 0;i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            int newK = g[x][y] + (validCells > 1 ? 1 : 0);
            if(newK <= k && newX > -1 && newY > -1 && newX < n && newY < m && matrix[newX][newY] != 'X' &&  g[newX][newY] > newK){
                g[newX][newY] = newK;
                q.push({newX, newY});
            }
        }
    }
    return g[eX][eY] != k ? "Oops!" : "Impressed";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
