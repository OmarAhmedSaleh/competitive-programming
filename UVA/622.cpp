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
//const long long OO=4e18;
//const int oo=1e9;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,-1,1,1,-1,-1,1};

int global_it,sz,t;
char s[100000];
bool bad;
int exp();
int fac();
int com();

int fac(){
    // < factor > := < positiveinteger > | (< expression >)
    if(bad){
        return 0;
    }
    int ret=0;
    if(s[global_it]>='0'&&s[global_it]<='9'){
        while(s[global_it]>='0'&&s[global_it]<='9'){
            ret*=10;ret+=s[global_it++]-'0';
        }
        return ret;
    }else{
        if(s[global_it]=='('){
            global_it++;
            ret=exp();
            if(s[global_it]!=')'){
                bad=1;
            }
            global_it++;
        }else{
            bad=1;
        }
    }
    return ret;
}
int com(){
    // < component > := < factor > | < factor > * <component>
    if(bad){
        return 0;
    }
    int ret=fac();
    while(s[global_it]=='*'){
        global_it++;
        ret*=com();
    }
    if(s[global_it]!='\0'&&s[global_it]!='+'&&s[global_it]!=')'){
        bad=1;
    }
    return ret;
}
int exp(){
    // < expression > := < component > | < component > + < expression >
    if(bad){
        return 0;
    }
    int ret=com();
    while(s[global_it]=='+'){
        global_it++;
        ret+=exp();
    }
    if(s[global_it]!='\0'&&s[global_it]!='*'&&s[global_it]!=')'){
        bad=1;
    }
    return ret;
}


int main(){
    scanf("%d",&t);
    while(t-->0){
        cin>>s;
        sz=(int)strlen(s);
        bad=global_it=0;
        int ans=exp();
        if(global_it!=sz){
            bad=1;
        }
        if(bad){
            cout<<"ERROR"<<endl;
        }else{
            cout<<ans<<endl;
        }
    
    }

    return 0;
}
