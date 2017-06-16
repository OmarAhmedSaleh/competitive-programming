/*
-sort letters then word to Dictionary (Trie data structure) (search O(|S|))
-for each group of letters (Query) try all combinations (2^n) (n<=10)
-search if you have this combination of letters (storted) in dictionary
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

/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
bool f;
struct trie{
    trie* child[26];
    bool ed;
    trie(){
        memset(child,0,sizeof(child));
        ed=0;
    }
    void insert(char *str){
        if(*str=='\0'){
            ed=1;
            return ;
        }
        if(!child[*str-'a']){
            child[*str-'a']=new trie();
        }
        child[*str-'a']->insert(str+1);
    }
    void search(char *str){
        if(*str=='\0'){
            f=ed;
            return ;
        }
        if(!child[*str-'a']){
            return ;
        }
        child[*str-'a']->search(str+1);
    }
};
int n ,m, p ,v[10];
char s[10],s2[10],s3[10];
int main(){
    scanf("%d",&n);
    trie T;
    for(int i=0;i<n;i++){
        scanf(" %s",&s);
        sort(s,s+(int)strlen(s));
        T.insert(s);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int ans=0;
        scanf("%d",&p);
        for(int j=0;j<p;j++){
            scanf(" %c%d",&s2[j],&v[j]);
        }
        for(int j=0;j<(1<<p);j++){
            int sum=0,pos=0;
            for(int k=0;k<p;k++){
                if(j&(1<<k)){
                    sum+=v[k];
                    s3[pos++]=s2[k];
                }
            }
            s3[pos]='\0';
            sort(s3,s3+pos);
            f=0;
            T.search(s3);
            if(f){
                ans=max(ans,sum);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
