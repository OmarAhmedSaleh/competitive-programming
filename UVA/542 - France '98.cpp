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
    for(int k=0;k<9;k+=8){
        for(int i=k;i<k+4;i++){
            for(int j=k+4;j<k+8;j++){
                ans[i][2]+=ans[j][1]*p[i][j];
            }
            ans[i][2]*=ans[i][1];
        }
        for(int i=k+4;i<k+8;i++){
            for(int j=k;j<k+4;j++){
                ans[i][2]+=ans[j][1]*p[i][j];
            }
            ans[i][2]*=ans[i][1];
        }
    }
}

void get4(){
    for(int k=0;k<16;k+=16){
        for(int i=k;i<k+8;i++){
            for(int j=k+8;j<k+16;j++){
                ans[i][3]+=ans[j][2]*p[i][j];
            }
            ans[i][3]*=ans[i][2];
        }
        for(int i=k+8;i<k+16;i++){
            for(int j=k;j<k+8;j++){
                ans[i][3]+=ans[j][2]*p[i][j];
            }
            ans[i][3]*=ans[i][2];
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
    get1();get2();get3();get4();
    for(int i=0;i<16;i++){
        printf("%-10s p=%.2lf%c\n",s[i].c_str(),ans[i][3]*100,'%');
    }
    return 0;
}
