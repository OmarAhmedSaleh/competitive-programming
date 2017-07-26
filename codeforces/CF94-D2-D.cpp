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
const double EPS=1e-11;
//const long long OO=4e18;
//const int oo=1e9;
//int dx[8]={1,-1,0,0,1,-1,1,-1};
//int dy[8]={0,0,-1,1,1,-1,-1,1};
int n , m , w;
vector< pair<int,double> > ans[50];
double c[50];
int occ[50];
int main(){
    scanf("%d%d%d",&n,&w,&m);
    int nn=n;
    double d=n*w;d/=m;
    double dw=d;
    int pos=0;
 //  printf("%d %.5lf %.5lf\n",in_d,d,dw);

    if(n){
       /*
        double delta=w;delta/=dw;
      //  printf("%d %.5lf %.5lf\n",in_d,delta,dw);
        int in_delta=delta;
        if(in_delta>2){
            puts("NO");
            return 0;
        }
        
        delta-=in_delta;
        if(in_delta == 2){delta=1;}
        for(int i=0;i<m;i+=2){
            if(i+1 == m){break;}
            c[i]+=dw;
            ans[i].push_back(make_pair(pos,dw));
            ans[i+1].push_back(make_pair(pos,delta*dw));
            c[i+1]+=delta*dw;
            n--;
            pos++;
        }
        if(n<0){
            puts("NO");
            return 0;
        }
         */
        int cnt=0;
        double cur=w;
        for(int i=0;i<m;i++){
            if(pos>=nn){break;}
            if(fabs(c[i]-dw)>EPS){
                double df=dw-c[i];
                /*
                if(cnt==1 && df<cur){
                   // while(mm>-1&&c[i]>(dw+(w*in_d))){mm--;}
                    //if(mm==-1){break;}
                    c[mm]+=cur;
                    i=-1;
                    ans[mm].push_back(make_pair(pos++,cur));
                    cnt=0;
                    cur=w;
                    continue;
                }
                 */
                c[i]+=min(df,cur);
                ans[i].push_back(make_pair(pos,min(df,cur)));
                cur-=min(df,cur);
                cnt++;
               /* if(cnt==2&&fabs(cur-0)>EPS){
                    puts("NO");
                    return 0;
                }
                */
                if(fabs(cur-0)<EPS){
                    cur=w;
                    cnt=0;
                    i=-1;
                    pos++;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<ans[i].size();j++){
            occ[ans[i][j].first]++;
        }
        if(fabs(c[i]-dw)>EPS){
            puts("NO");
           // cerr<<" 1 "<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        if(!occ[i]||occ[i]>2){
            puts("NO");
           // cerr<<" 2 "<<endl;
            return 0;
        }
    }
    printf("YES\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<ans[i].size();j++){
            if(j){
                printf(" ");
            }
            printf("%d %.6lf",ans[i][j].first+1,ans[i][j].second);
        }
        printf("\n");
    }
    
    return 0;
}
