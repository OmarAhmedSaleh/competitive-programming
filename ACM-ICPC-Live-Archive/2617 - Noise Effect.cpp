/*
 Complete search problem 
 try all possible ways
 
 */

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
int l, a[444][444], b[444][444], c[444][444];
void copy(){
    for(int i=0;i<l;i++){
        for(int j=0;j<l;j++){
            b[i][j]=c[i][j];
        }
    }
    
}
void rot(){
    int row=0,col=0;
        for(int j=l-1;j>-1;j--){
            for(int i=0;i<l;i++){
                c[row][col++]=b[i][j];
                if(col==l){col=0;}
            }
            row++;
        }
    copy();
    
}
void ref(){
    int row=0,col=0;
    for(int j=l-1;j>-1;j--){
        for(int i=0;i<l;i++){
            c[row++][col]=b[i][j];
            if(row==l){row=0;}
        }
        col++;
    }
    copy();
    
}
double ans;
int main(){
    while(scanf("%d",&l)==1){
        if(!l){break;}
        ans=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                scanf("%d",&b[i][j]);
            }
        }
        
 
    for(int k=0;k<4;k++){
        double sum=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(abs(a[i][j]-b[i][j])<101){sum+=1;}
            }
        }
        sum/=l*l;
        ans=max(sum,ans);
        rot();
    }
    rot();
    ref();
    for(int k=0;k<4;k++){
        double sum=0;
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(abs(a[i][j]-b[i][j])<101){sum+=1;}
            }
        }
        sum/=l*l;
        ans=max(sum,ans);
        rot();
    }
        ans*=100;
        printf("%.2lf\n",ans);
    }
    return 0;
}
