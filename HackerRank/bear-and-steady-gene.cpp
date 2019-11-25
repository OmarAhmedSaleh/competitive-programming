#include <bits/stdc++.h>

using namespace std;

// Complete the steadyGene function below.
int steadyGene(string gene) {
    int n = (int)gene.size();
    vector < vector < int > > acc(n , vector < int > (26 , 0));
    int n4 = n / 4; 
    string G = "ATCG";
    for(int i = 0;i < n ; i++){
        acc[i][gene[i] - 'A']++;
        if(i == 0){continue;}
        for(int j = 0; j < 4 ; j++){
            acc[i][G[j] - 'A'] += acc[i - 1][G[j] - 'A'];
        }
    }
    bool bad = false;
    for(int i = 0;i < 4 ; i++){
        if(acc[n - 1][G[i] - 'A'] != n4){
            bad = true;
            break;
        }
    }
    if(!bad){
        return 0;
    }
    int best = n;
    for(int i = 0;i < n ; i++){
        int high = n - 1;
        int low = i;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            vector < int > v = acc[mid];
            if(i > 0){
                for(int j = 0; j < 4 ; j++){
                    v[G[j] - 'A'] -= acc[i - 1][G[j] - 'A'];
                }
            }
            bool less = false;
            for(int j = 0 ; j < 4 ; j++){
                if(acc[n - 1][G[j] - 'A'] > n4 && v[G[j] - 'A'] < (acc[n - 1][G[j] - 'A'] - n4)){
                    less = true;
                    break;
                }
            }
            if(less){
                low = mid + 1;
            }else{
                high = mid - 1;
                ans = mid;

            }
        }
        if(ans != -1){
             best = min(best , ans - i + 1);
        }
        
    }
    return best;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
