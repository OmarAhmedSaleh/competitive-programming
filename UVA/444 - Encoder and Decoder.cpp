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
string s;
map<int,char> ic;
int main(){
    int w=97;
    for(char i='a';i<='z';i++){
        ic[i]=w;
        w++;
    }
    w=65;
    for(char i='A';i<='Z';i++){
        ic[i]=w;
        w++;
    }
    ic[32]=' ';
    ic[33]='!';
    ic[44]=',';
    ic[46]='.';
    ic[58]=':';
    ic[59]=';';
    ic[63]='?';
 
    while(getline(cin,s)){
        int n=(int)s.size();
        string ans="";
        if(isdigit(s[0])){
            reverse(s.begin(),s.end());
            int m=0;
            int sz=0;
            for(int i=0;i<n;i++){
                if(ic.count(m)){ans+=ic[m];m=0; sz=0;}
                m*=10;
                m+=s[i]-'0';
            }
            if(ic.count(m)){ans+=ic[m];m=0; sz=0;}
        }else{
            for(int i=0;i<n;i++){
                int m=s[i];
                string t="";
                while(m){t+=m%10 +'0';m/=10;}
                reverse(t.begin(),t.end());
                ans+=t;
        
            }
            reverse(ans.begin(),ans.end());
        
        }
        cout<<ans<<endl;
    }
    
    return 0;//rev Ab steps
}
