#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int tc;
    cin >> tc;
    const int N = 1e5;
    vector < int > isPrime(N , 1);
    isPrime[1] = isPrime[0] = 0;
    for(int i = 4 ; i < N ; i += 2){
        isPrime[i] = 0;
    }
    for(int i = 3 ; i < N ; i++){
        if(!isPrime[i] || 1LL * i * i > N){
            continue;
        }
        for(int j = i * i ; j < N ; j += i){
            isPrime[j] = 0;
        }
    }
    vector < int > primes;
    for(int i = 2 ; i < N ; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    for(int tt = 0 ; tt < tc; tt++){
        int n;
        cin >> n;
        int ans[3] = {1 , 1 ,1};
        vector < int > fact;
        int it = 0;
        for(int i = 0;i < (int)primes.size(); i++){
            while(n % primes[i] == 0){
                fact.push_back(primes[i]);
                n /= primes[i];
            }
        }
        if(n != 1){
          fact.push_back(n);
        }
        if(fact.size() > 0){
            ans[0] = fact[0];
            it++;
        }
        for(int i = 1; i <(int)fact.size(); i++){
            ans[it] *= fact[i];
            if(it < 2){
                int next = 1;
                for(int j = 0;j < 3 ; j++){
                 if(it != j && ans[it] == ans[j]){
                       next = 0;
                    }
                }
                it += next;
            }
        }
        sort(ans , ans + 3);
        bool bad = ans[0] == 1;
        for(int i = 1 ; i < 3 ; i++){
            if(ans[i] == ans[i - 1] ){
                bad = true;
            }
        }
        if(!bad){
            cout << "YES" << endl;
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
