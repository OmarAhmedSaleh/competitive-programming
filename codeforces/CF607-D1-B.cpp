#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <map>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
int t,k;
int a,b;
const int N=505;
const int INF=1000000007;
int c[N];
int f[N][N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    
    for(int i=n-1;i>-1;i--){
        for(int j=i;j<n;j++){
            if(i==j){
                f[i][i]=1;
             //   cout<<f[i][j]<<" "<<i<<" "<<j<<endl;

                continue;
            }
            if(i+1==j){
                if(c[i]==c[j]){f[i][j]=1;}else{f[i][j]=2;}
              //  cout<<f[i][j]<<" "<<i<<" "<<j<<endl;

                continue;
            }
            f[i][j]=INF;
            for(int k=i;k<j;k++){
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
            if(c[i]==c[j]){
                f[i][j]=min(f[i][j],f[i+1][j-1]);}
        
           // cout<<f[i][j]<<" "<<i<<" "<<j<<endl;

        }
    
    }
    
    printf("%d\n",f[0][n-1]);
    return 0;
}
