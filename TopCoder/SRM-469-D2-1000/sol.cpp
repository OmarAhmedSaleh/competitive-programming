#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <queue>

using namespace std;

class TheMoviesLevelThreeDivTwo{
public:
int n;
vector<int> jj;
vector<int> bb;
    int ret=0;

vector<char> s;
void bk(int idx){
if(idx==n){
 queue<pair<int,int> > b,o;
for(int i=0;i<s.size();i++){
            // 1 -> Bu
            // 2 -> Jo
    if(s[i]=='1'){b.push(make_pair(bb[i],i));}
    if(s[i]=='2'){o.push(make_pair(jj[i],i));}
        }
int c[2]={0,0};
while(!b.empty()&&!o.empty()){
    int pos[2]={b.front().second,o.front().second};
    int mn=min(b.front().first,o.front().first);
    b.front().first-=mn;
    o.front().first-=mn;
    if(!b.front().first){
    c[0]++;
    b.pop();
    if(s[pos[0]]=='1'){o.push(make_pair(jj[pos[0]],pos[0]));}
    }
    if(!o.front().first){
    c[1]++;
    o.pop();
    if(s[pos[1]]=='2'){b.push(make_pair(bb[pos[1]],pos[1]));}
    }

}
c[0]+=b.size();
c[1]+=o.size();
ret+=(c[0]==c[1]&&c[0]==n);
return ;

}
s.push_back('1');
bk(idx+1);
s.pop_back();
s.push_back('2');
bk(idx+1);
s.pop_back();
}
 int find(vector <int> timeJ, vector <int> timeB){
    jj=timeJ;
    bb=timeB;
    n=timeJ.size();
    s.clear();
    bk(0);
    return ret;
 }



};
