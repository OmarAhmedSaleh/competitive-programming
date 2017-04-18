/*
you can create number of stacks = number of distinct letters (at most 26)
    or
for each char try to insert it at stack whose top element greater than or equal to it
    or
  create new stack
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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
string s;
int tt=1;
int main(){
    while(cin>>s){
        if(s=="end"){
            break;
        }
        int sz=(int)s.size();
        vector<stack<char> > all;
        set<char> st;
        for(int i=0;i<sz;i++){
            st.insert(s[i]);
        }
        for(int i=0;i<sz;i++){
            bool put=0;
            for(int j=0;j<all.size();j++){
                if(all[j].top()>=s[i]){
                    all[j].push(s[i]);
                    put=1;
                    break;
                }
            }
            if(!put){
                stack<char> c;
                c.push(s[i]);
                all.push_back(c);
            }
        }
        printf("Case %d: %d\n",tt++,min((int)st.size(),(int)all.size()));
    }
    return 0;
}
