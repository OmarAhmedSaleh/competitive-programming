// https://www.hackerrank.com/challenges/bigger-is-greater/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int idx = -1;
    int swapWith = -1;
    for(int i = (int)w.size() - 1;i > -1;i--){
        for(int j = i + 1; j < (int)w.size(); j++){
            if(w[j] > w[i]){
                if(swapWith == -1 || w[swapWith] > w[j]){
                    swapWith = j;
                }
            }
        }
        if(swapWith != -1){
            idx = i + 1;
            swap(w[i], w[swapWith]);
            break;
        }
    }
    if(idx == -1){
        return "no answer";
    }
    for(int i = idx; i < (int)w.size(); i++){
        for(int j = i + 1 ; j < (int)w.size(); j++){
            if(w[j] < w[i]){
                swap(w[i], w[j]);
            }
        }
    }
    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
