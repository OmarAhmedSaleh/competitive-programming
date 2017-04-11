
/*
first player sort items in decreasing order and take item (left->right)
second player (you) , want to take item ( first player didn’t take it) 

you want to maximise possible sum regardless of the first player’s moves?

{
WA approach “take max item ”
test case
4
a[]=9 8 7 6
b[]=1 3 1 5
first player take first item a[0]=9 
a[]=-1 8 7 6
b[]=-1 3 1 5
you take item b[3]= 5  cur=5;
a[]=-1 8 7 -1
b[]=-1 3 1 -1
first player take a[1]=8
you take b[2]=1 cur=5+1
output : 6
correct output: 8
first player take item = a[0]
you b[1]=3
first player a[2]=7
you b[3]=5


}

AC approach is :

start from i=1;

if you want to take i’th item you should leave (i+1)’th 

if you want to take i and i+1 you should leave the smallest value you took before

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
int n;
pair<int,int> a[100005];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].first);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].second);
    }
    sort(a,a+n);
    reverse(a,a+n);
    if(n%2==0){
        ans+=a[n-1].second;
        n--;
    }
    multiset<int> st;
    for(int i=1;i<n;i+=2){
        st.insert(a[i].second);
        st.insert(a[i+1].second);
        st.erase(st.begin());
    }
    multiset<int> :: iterator it=st.begin();
    while(it!=st.end()){
        ans+=(*it);
        it++;
    }
    printf("%lld\n",ans);
    return 0;
}
