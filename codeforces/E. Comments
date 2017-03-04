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

using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 */

const int N=1000006;
struct word{
    string s;
    int l;
    int need;
};
stack<word>st;
int sz;
string com;
vector<string> all[N];
int main(){
    cin>>com;
    sz=(int)com.size();
    int mx=0;
    string t="";
    for(int i=0;i<sz;i++){
        if(com[i]==','){
            int kk=0;
            for(int j=i+1;j<sz;j++){
                if(com[j]==','){i=j;break;}
                kk*=10;
                kk+=com[j]-'0';
            }
            word w;
            w.s=t;
            w.l=1;
            w.need=kk;
            if(st.size()>0){
                int las=st.top().l;
                w.l=las+1;
                word qq=st.top();
                st.pop();
                qq.need--;
                if(qq.need){
                    st.push(qq);
                }
            }
            all[w.l].push_back(w.s);
            mx= max(w.l,mx);
            if(kk){
                st.push(w);
            }

            t="";
        }else{
            t+=com[i];
        }
        while(st.size()&&!st.top().need){st.pop();}
    }
    cout<<mx<<endl;
    for(int i=1;i<=mx;i++){
        for(int j=0;j<all[i].size();j++){
            if(j){
            cout<<" ";
            }
            cout<<all[i][j];
        }
        cout<<endl;
    }
    /*
     -- Valid
     -- const (10^9>sz)
     -- array index
     -- less or more , check if
     -- even or odd
     */
    return 0;
}
  
