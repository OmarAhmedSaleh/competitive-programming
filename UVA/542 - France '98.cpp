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
double p[16][16],ans[16][4];
string s[16];
void get1(){
    for(int i=0;i<16;i++){
        int j=i;
        if(i&1){
            j--;
        }else{
            j++;
        }
        ans[i][0]=p[i][j];
    }
}
void get2(){
    for(int k=0;k<13;k+=4){
        for(int i=k;i<k+2;i++){
            for(int j=k+2;j<k+4;j++){
                ans[i][1]+=ans[j][0]*p[i][j];
            }
            ans[i][1]*=ans[i][0];
        }
        for(int i=k+2;i<k+4;i++){
            for(int j=k;j<k+2;j++){
                ans[i][1]+=ans[j][0]*p[i][j];
            }
            ans[i][1]*=ans[i][0];
        }
    }
}

void get3(){
    for(int i=0;i<4;i++){
        for(int j=4;j<8;j++){
            ans[i][2]+=ans[i][1]*(ans[j][1]*p[i][j]);
        }
    }
    for(int i=4;i<8;i++){
        for(int j=0;j<4;j++){
            ans[i][2]+=ans[i][1]*(ans[j][1]*p[i][j]);
        }
    }
    for(int i=8;i<12;i++){
        for(int j=12;j<16;j++){
            ans[i][2]+=ans[i][1]*(ans[j][1]*p[i][j]);
        }
    }
    for(int i=12;i<16;i++){
        for(int j=8;j<12;j++){
            ans[i][2]+=ans[i][1]*(ans[j][1]*p[i][j]);
        }
    }
    
    
}

void get4(){
    for(int i=0;i<8;i++){
        ans[i][3]=0;
        for(int j=8;j<16;j++){
        ans[i][3]+=ans[i][2]*ans[j][2]*p[i][j];
        }
    }
    for(int i=8;i<16;i++){
       ans[i][3]=0;
        for(int j=0;j<8;j++){
            ans[i][3]+=ans[i][2]*ans[j][2]*p[i][j];
        }
    }
}
int main(){
    for(int i=0;i<16;i++){
        cin>>s[i];
    }
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            scanf("%lf",&p[i][j]);
            p[i][j]/=100;
        }
    }
    get1();
    get2();
    get3();
    get4();
    for(int i=0;i<16;i++){
        printf("%-10s p=%.2lf%c\n",s[i].c_str(),ans[i][3]*100,'%');
    }
    return 0;
}
