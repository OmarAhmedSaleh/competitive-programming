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

int t , n, m,a[30000],b[30000];
multiset<int> ms;

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int pos=0;
        for(int j=0;j<m;j++){
            scanf("%d",&b[j]);
        }
        ms.clear();
        multiset<int> :: iterator it=ms.begin();
        bool no=1;
        for(int i=0;pos<m&&i<n;i++){
            ms.insert(a[i]);
            if(i&&(*it)>a[i]){
                if(!no){
                    it--;
                }
            }
            while(pos<m&&b[pos]<=i+1){
                if(b[pos]==i+1){
                    if(no){
                        it=ms.begin();
                        no=0;
                    }else{
                        it++;
                    }
                    printf("%d\n",*it);
                }
                pos++;
            }
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}
