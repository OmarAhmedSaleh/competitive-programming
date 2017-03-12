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
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */



int n,m,k;


int main(){
    cin>>n>>m>>k;
    if(n%2==0){
        cout<<"Marsel"<<endl;
        return 0;
    }
    for(int i=1;i*i<=m;i++){
        if(m%i==0){
            int j=m/i;
            if(j>=k&&i>1){
            cout<<"Timur"<<endl;
            return 0;
            }
            if(j>1&&i>=k){
                cout<<"Timur"<<endl;
                return 0;
            }
        }
    
    }
    cout<<"Marsel"<<endl;
    return 0;
}
