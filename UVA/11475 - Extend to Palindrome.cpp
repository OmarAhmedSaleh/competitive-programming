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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
string s,r;
int sz;
int z[100005];

void z_algorithm() {
    //z[0] = 0;
    int L = -1, R = -1;
    sz=(int)s.size();
    for(int i=0;i<sz;i++) {
        z[i] = i >= R ? 0 : min(R-i, z[i-L]);
        while (i+z[i] < sz && s[i+z[i]] == r[z[i]]) ++z[i];
        if (i+z[i] > R) L = i, R = i+z[i];
    }
}

int main(){
    while(cin>>s){
        r=s;
        reverse(r.begin(),r.end());
        z_algorithm();
        int pos;
        for(int i=0;i<sz;i++){
            if(i+z[i]>=sz){
                pos=i;
                break;
            }
        }
        printf("%s",s.c_str());
        for(int i=pos-1;i>-1;i--){
            printf("%c",s[i]);
        }
        puts("");
  
    }
    return 0;
}
