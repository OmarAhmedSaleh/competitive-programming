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
