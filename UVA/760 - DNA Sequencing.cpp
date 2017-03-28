#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <complex>

using namespace std;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

typedef pair<int, int> ii;

#define MAX_N 100010                         // second approach: O(n log n)
string T,P;                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// and current suffix T+SA[i]

//bool cmp(int a, int b) { return strcmp(T + a, T + b) < 0; }      // compare

void countingSort(int k) {                                          // O(n)
    int i, sum, maxi = max(300, n);   // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA() {         // this version can go up to 100000 characters
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        countingSort(k);  // actually radix sort: sort based on the second item
        countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
            (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    } }

vector<int> hh;

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
        while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

int owner(int idx) { return (idx < n-m-1) ? 1 : 2; }
vector<pair<int,int > >all;
int k=2;
ii LCS() {                 // returns a pair (the LCS length and its index)
    int i, idx = 0, maxLCP = -1;
    for (i = 1; i < n; i++){                         // O(n), start from i = 1
        vector<int>mark(11,0);
        int mn=LCP[i];
        for(int j=0;j<k;j++){
            int pos=lower_bound(hh.begin(),hh.end(),SA[i-j])-hh.begin();
            while(pos<hh.size()&&SA[i-j]>hh[pos]){pos++;}
            mark[pos]=1;
            if(j+1<k){
                mn=min(LCP[i-j],mn);
            }
        }
        int cnt=0;
        for(int j=0;j<11;j++){
            cnt+=mark[j];
        }
        // cout<<cnt<<endl;
        if (cnt==k && mn> maxLCP ){
            maxLCP =mn, idx = i;
            all.clear();
        }
        if (cnt==k && mn== maxLCP ){
            maxLCP =mn, idx = i;
            all.push_back(make_pair(mn,idx));
        }
        
    }
    maxLCP=max(maxLCP,0);
    return ii(maxLCP, idx);
}
bool fir=1;

int main() {
    while(cin>>T){
        if(fir){
            fir=0;
        }else{
            cout<<endl;
        }
        all.clear();
        hh.clear();
        cin>>P;
        hh.push_back((int)T.size()-1);
        m=(int)P.size();
        T+='#';
        T+=P;
        hh.push_back((int)T.size()-1);
        n=(int)T.size();
        constructSA();
        computeLCP();
        pair<int,int> ret = LCS();
        if(ret.first<1){
            cout<<"No common sequence."<<endl;
        }else{
            vector<string> ans;
            for(int i=0;i<all.size();i++){
                int from,sz;
                from=all[i].second;
                sz=all[i].first;
                string ss="";
                for(int j=0;j<sz;j++){
                    ss+=T[SA[from]+j];
                }
                ans.push_back(ss);
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++){
                if(i&&ans[i]==ans[i-1]){continue;}
                cout<<ans[i]<<endl;
            }
        }
        
    }
    return 0;
}
