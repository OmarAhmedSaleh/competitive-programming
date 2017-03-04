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
const double EPS=1e-8;
const int N=100005;
typedef complex<double> point;
#define X real()
#define Y imag()
#define cp(a,b) (conj(a)*b).imag()
#define dp(a,b) (conj(a)*b).real()
#define lengthsq(a)    dp(a,a)
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int n , a, b, k;
string s;

int main(){
    scanf("%d%d%d%d",&n,& a,&b,&k);
    cin>>s;
    vector<pair<int,int> > v;
    int all=0;
    s+='1';
    n=(int)s.size();
    bool in=0;
    int st=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(in){
                continue;
            }else{
                in=1;st=i;
                continue;
            }
        }
        if(s[i]=='1'){
            if(!in){continue;}
            in=0;
            v.push_back(make_pair(st,i-1));
            all+=(i-st)/b;
        }
    }
    vector<int> ans;
    for(int i=0;i<v.size();i++){
        if(all<a){break;}
        int cur=v[i].first;
        cur--;
        int df=((v[i].second+1)-v[i].first)/b;
        int mn=min(df,(all-a)+1);
        all-=mn;
        for(int j=0;j<mn;j++){
            ans.push_back(cur+b);
            cur+=b;
    
        }
    
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<ans.size();i++){
        if(i){
            printf(" ");
        }
        printf("%d",ans[i]+1);
    }
    puts("");
    
    return 0;//rev Ab steps
}
