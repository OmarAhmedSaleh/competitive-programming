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

using namespace std;
// http://codeforces.com/problemset/gymProblem/100935/F

int t;
int best,c,n;
char s[101];
class trie{
public:
trie* child[33];
int cnt;
trie(){
cnt=0;
memset(child,0,sizeof(child));
}
void in(char *str,int l){
if(l>best&&cnt>2){best=l;c=cnt;}
if(best==l){c=max(c,cnt);}
if(*str=='\0'){return ;}
int pos=*str-'a';
if(child[pos]==0){
   child[pos]=new trie();

}
child[pos]->cnt++;
child[pos]->in(str+1,l+1);

}

};

int main()
{
    //freopen("in.txt","r",stdin);
scanf("%d",&t);
for(int tt=1;tt<=t;tt++){
    scanf("%d",&n);
    int sz;
  trie t;
  best=c=0;
for(int i=0;i<n;i++){
scanf(" %s",&s);
       sz=strlen(s);
  reverse(s,s+sz);
  for(int j=0;j<sz;j++){
    s[j]=tolower(s[j]);
  }
  t.in(s,0);
    }
printf("Case %d:\n%d %d\n",tt,best,c);
}

    return 0;
}
