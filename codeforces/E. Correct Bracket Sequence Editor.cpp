#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int MAX=500055;
int n,m,pos,l[MAX],r[MAX],pp[MAX];
char s[MAX],in[MAX];
string ans;
int fir;
inline int getr(){
return r[pos];

}
inline int getl(){
    return l[pos];

}
inline void del(){
int pa=pp[pos];
if(pa>pos){
 if(l[pos]==-1){fir=r[pa];}

        if(r[pa]!=-1){
 l[r[pa]]=l[pos];
 }
 if(l[pos]!=-1){
 r[l[pos]]=r[pa];
 }
       int ne=r[pa];
  if(ne==-1){ne=l[pos];}
  pos=ne;
}else{
    if(l[pa]==-1){fir=r[pos];}

if(r[pos]!=-1){
l[r[pos]]=l[pa];
}
if(l[pa]!=-1){
r[l[pa]]=r[pos];
}
int ne=r[pos];
if(ne==-1){ne=l[pa];}
pos=ne;

}

}
void getans(int ll){
if(ll==-1){return;}
ans+=s[ll];
getans(r[ll]);
}
int main()
{
// c file b s
// save code b s
//freopen("in.txt","r",stdin);

scanf("%d %d %d",&n,&m,&pos);
pos--;
scanf(" %s",&s);
l[0]=-1;
r[n-1]=-1;
for(int i=0;i<n-1;i++){
   r[i]=i+1;
}
for(int i=1;i<n;i++){
    l[i]=i-1;
}
fir=0;
stack<pair<char ,int> > st;
for(int i=0;i<n;i++){
    if(s[i]=='('){st.push(make_pair(s[i],i));continue;}
pair<char ,int> rr=st.top();
if(rr.first=='('){
    st.pop();
    pp[rr.second]=i;
    pp[i]=rr.second;
   }else{
   st.push(make_pair(s[i],i));
   }
}
scanf(" %s",&in);
int sz=strlen(in);
for(int i=0;i<sz;i++){
if(in[i]=='R'){
pos=getr();

continue;
}
if(in[i]=='L'){
pos=getl();

continue;
}
del();

}
ans="";
getans(fir);
printf("%s\n",ans.c_str());

    return 0;
}
