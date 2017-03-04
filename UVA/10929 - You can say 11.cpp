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

int main(){
    while(1){
        cin>>s;
        if(s.size()==1&&s[0]=='0'){break;}
        reverse(s.begin(),s.end());
        int mod=(s[0]-'0')%11;

        for(int i=1;i<s.size();i++){
            mod*=10;
            mod+=(s[i]-'0');
            mod%=11;
        }
        reverse(s.begin(),s.end());
        if(!mod){
            cout<<s<<" is a multiple of 11."<<endl;
        }else{
            cout<<s<<" is not a multiple of 11."<<endl;
        }
    
    }
    
    
    
    
    return 0;//rev Ab steps
}
