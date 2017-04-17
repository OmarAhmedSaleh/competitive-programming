
/*
calculate grundy numbers from 0 to 60 (using get() function)
 and save them
 
 then solve it as Nim game ,pile size = grundy(a)
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

int mex(set<int> v){
    int ret=0;
    while(v.find(ret)!=v.end()){
        ret++;
    }
   return ret;
}
map<set<int>,int> mp[66];
int get(int idx,set<int> s){
    if(!idx){
        return 0;
    }
    int ret=0;
    if(mp[idx].count(s)){
        return mp[idx][s];
    }
    set<int> v;
    for(int i=1;i<=idx;i++){
        if(s.find(i)==s.end()){
            set<int> ss=s;
            ss.insert(i);
            v.insert(get(idx-i,ss));
        }
    }
    
    return mp[idx][s]=mex(v);
}
int n ,a;
long long x;
int g[66]={0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
int main(){
    /*

    cout<<"{";
    set<int> st;
    for(int i=0;i<=60;i++){
    if(i){cout<<",";}
    cout<<get(i,st);
    }
    cout<<"}";
     */
    scanf("%d",&n);
        x=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
                x^=g[a];
        }
        if(x==0){
            puts("YES");
        }else{
            puts("NO");
        }
    return 0;
    
}
