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
using namespace std;
/*
 -- Valid
 -- const (10^9>sz)
 -- array index
 -- less or more , check if
 -- even or odd
 -- inequality
 */
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const int N=30;
int q , n;
char c;
vector<int> bits;
long long ans;
struct trie{
    trie *child[2];
    int cnt;
    int number;
    trie(){
        memset(child,0,sizeof(child));
        cnt=0;
        number=-1;
    }
    void insert(int it){
        if(it==bits.size()){
            cnt++;
            number=n;
            return ;
        }
        if(!child[bits[it]]){
            child[bits[it]]=new trie();
        }
        child[bits[it]]->insert(it+1);
        cnt++;
    }
    
    void remove(int it){
        if(it==bits.size()){
            cnt--;
            if(!cnt){number=-1;}
            return ;
        }
        if(!child[bits[it]]){
            return;
        }
        child[bits[it]]->remove(it+1);
        cnt--;
        
    }
    void search(int it){
        if(number!=-1){
            ans=max(ans,(long long)n^number);
        }
        if(it==bits.size()){return ;}
        if(child[0]&&child[1]&&child[1]->cnt&&child[0]->cnt){
            if(bits[it]){
                child[0]->search(it+1);
                return ;
            }
            child[1]->search(it+1);
            return ;

        }
        if(child[0]&&child[0]->cnt){child[0]->search(it+1);}
        if(child[1]&&child[1]->cnt){child[1]->search(it+1);}
        
    }
};
int main(){
    scanf("%d",&q);
    trie T;
    while(q--){
        scanf(" %c %d",&c,&n);
        bits.clear();
        if(c=='+'){
            for(int i=0;i<N;i++){
                if(n&(1<<i)){
                    bits.push_back(1);
                }else{
                    bits.push_back(0);
                }
                
                
            }
            reverse(bits.begin(),bits.end());

            T.insert(0);
            
        }
        
        if(c=='-'){
            for(int i=0;i<N;i++){
                if(n&(1<<i)){
                    bits.push_back(1);
                }else{
                    bits.push_back(0);
                }
                
                
            }
            reverse(bits.begin(),bits.end());

            T.remove(0);
            
        }
        if(c=='?'){
            for(int i=0;i<N;i++){
                int ww=0;
                if(n&(1<<i)){
                    ww=1;
                }
                bits.push_back(ww);
                
                }
            ans=n;
            reverse(bits.begin(),bits.end());
            T.search(0);
            printf("%lld\n",ans);
        }
    }
    
    
    return 0;//rev Ab steps
}
