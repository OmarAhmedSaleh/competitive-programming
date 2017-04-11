
/*
here you want to decompose string P into substrings such that each one is a prefix of string T

i will use KMP algorithm to calculate at each index the longest proper prefix (T) equal to suffix (P)

try to build string from the right to the left
start with cur=P.size()-1;
cur=(cur-longest_prefix_at[cur]);
if (longest proper prefix at cur position == 0 ) it means that it is Impossible to decompose string P , Stop
stop when cur < 0

*/
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


string T,P;
vector<int> ans;

int fil[150004],n,m,idx,sz;
void ff(){
    fil[0]=0;
    int k=0;
    for(int i=1;i<n;i++){
        while(k>0 && T[k]!=T[i]){k=fil[k-1];}
        if(T[i]==T[k]){
           k++;
        }
        fil[i]=k;
       
        
    }

}
bool f;
bool sp[75001];
int main() {
    cin>>T;
    sz=(int)T.size();
    cin>>P;
    m=(int)P.size();
    T+='#';
    T+=P;
    n=(int)T.size();
    ff();
    ans.clear();
    int pos=n-1;
    while(fil[pos]){
        pos-=fil[pos];
        ans.push_back(pos-sz);
        if(T[pos]=='#'){f=1;break;}

    }
    if(!f){
        printf("Yes\n");
    }else{
        if(ans.size()){
            reverse(ans.begin(),ans.end());
        }
            printf("No\n");
        for(int i=1;i<ans.size();i++){
            sp[ans[i]]=1;
        }
        for(int i=0;i<P.size();i++){
            if(sp[i]){printf(" ");}
            printf("%c",P[i]);
            
        }
        printf("\n");
    }
    
    
    return 0;
}
