#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
#include<stack>
#include<set>
#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#include<cmath>
using namespace std;
vector<pair<int,int> > all;
bool done[1000006];
string s;
int ans,sz;


int main(){
    cin>>s;
    sz=(int)s.size();
    int st,ed;
    st=ed=0;
    bool op=0;
    while(ed<sz){
        if(s[ed]=='0'&&op){
        all.push_back(make_pair(st,ed-1));
            op=0;
        }
        if(s[ed]=='1'&&!op){
            op=1;
            st=ed;
        }
        ed++;
        if(op&&ed==sz){
            all.push_back(make_pair(st,ed-1));
            op=0;
        }
    }
    int seq=1;
    pair<int,int> cur;
    cur=all.back();
    all.pop_back();
    bool bl=0;
    while(all.size()){
        if(cur.first!=cur.second){bl=1;}
        pair<int,int> nxt=all.back();
        all.pop_back();
        // merge
        if(nxt.second+2==cur.first){
        if(nxt.first!=nxt.second){bl=1;}
            seq++;
        }else{
            if(seq){
                ans+=seq;
                if(bl){
                    ans++;
                }
                bl=0;
            }
            seq=1;
        }
         cur=nxt;
    }
    if(cur.first!=cur.second){bl=1;}
    if(seq){
        ans+=seq;
        if(bl){
            ans++;
        }
        bl=0;
    }
    printf("%d\n",ans);
    return 0;
}
