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
int k,ans;
string s1,s2,temp;
struct trie{
    trie *child[26];
    bool ok;
    trie(){
        memset(child,0,sizeof(child));
        ok=0;
    }
    void get(int idx){
        if(!ok){
            ans++;
            ok=1;
        }
        if(idx==(int)temp.size()){
            return ;
        }
        if(child[temp[idx]-'a']==0){
            child[temp[idx]-'a']=new trie();
        }
        child[temp[idx]-'a']->get(idx+1);
    
    }
};
int main(){
    cin>>s1>>s2>>k;
    int sz=(int)s1.size();
    trie T;
    for(int i=0;i<sz;i++){
        int cnt=0;
        temp="";
        for(int j=i;j<sz;j++){
            if(s2[s1[j]-'a']=='0'){cnt++;}
            if(cnt>k){break;}
            temp+=s1[j];
        }
        if(temp.size()){
            T.get(0);
        }
    }
    cout<<max(ans-1,0)<<endl;
   
    return 0;
}
