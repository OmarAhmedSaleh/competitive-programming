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
// ss
using namespace std;
int dx[8]={-1,-1,-1,0,1,1, 1, 0};
int dy[8]={-1, 0, 1,1,1,0,-1,-1};
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */

const int N=1003;
const double EPS=1e-3;
struct segment{
    int x1,x2,y1,y2;
};
segment s[N];
int slide[N];
int n, tc, q, x, y;
int ans;
struct vec{
    double x,y;
};
vec tovec(int x1,int y1,int x2,int y2){
    vec v;
    v.x=(double)x2-x1;
    v.y=(double)y2-y1;
    return v;
}
double dot(vec a,vec b){
    return a.x*b.x+a.y+b.y;
}
double norm_sq(vec a){
    return a.x*a.x+a.y*a.y;
}
void sc(vec &v,double s){
    v.x*=s;
    v.y*=s;
}
bool same(segment st,int xx,int yy){
    
    return fabs((xx-st.x1)*(yy-st.y2)==(xx-st.x2)*(yy-st.y2))<EPS;
    
}
int tt=0;
void bk(){
    // cout<<x<<" "<<y<<endl;
    int nxt=-1;
    double mx=-1;
    for(int i=0;i<n;i++){
      
        // in range x1-----x2
        if(x>=min(s[i].x1,s[i].x2)&&x<=max(s[i].x1,s[i].x2)){
            vec ab;
            ab=tovec(s[i].x1,s[i].y1,s[i].x2,s[i].y2);
            //cout<<ab.y<<endl;
            vec ap;
            ap=tovec(s[i].x1,s[i].y1,x,y);
            // c =a+u*ab
            double u=dot(ab,ap)/norm_sq(ab);
            // cout<<u<<endl;
            sc(ab,u);
            // cout<<ab.y<<endl;
            double new_y=ab.y+s[i].y1;
            //cout<<new_y<<endl;
            if(new_y>y){continue;}
            if(new_y>mx){
                mx=new_y;
                nxt=i;
            }
        }
    }
    if(nxt==-1){
        ans=x;
        return ;
    }
    //cout<<nxt<<endl;
    if(slide[nxt]==0){
        x=s[nxt].x1;
        y=s[nxt].y1;
    }else{
        x=s[nxt].x2;
        y=s[nxt].y2;
        
    }
    bk();
}
int main(){
    scanf("%d",&tc);
    while(tc--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
            if(s[i].y1>s[i].y2){
                swap(s[i].x1,s[i].x2);
                swap(s[i].y1,s[i].y2);
            }
            if(s[i].y1>s[i].y2){
                slide[i]=1;
            }else{
                slide[i]=0;
            }
        }
        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&x,&y);
            bk();
            printf("%d\n",ans);
            
        }
        if(tc){puts("");}
        
    }
    return 0;
}
