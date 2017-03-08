#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>
#include <stdio.h>
using namespace std;
const int N=1000006;
string t,p;
int fail[N];
int mark[N];
void prekmp(){
    int k=0;
    for(int i=1;i<p.size();i++){
        while(k>0&&p[i]!=p[k]){
            k=fail[k-1];
        }
        if(p[i]==p[k]){
            fail[i]=++k;
        }else{
        fail[i]=k;
        }
        mark[fail[i]]++;
    }
    
}

int m;
int main(){
    cin>>p;
     m=(int)p.size();
    prekmp();
  
    mark[fail[m-1]]--;
   // for(int i=0;i<m;i++){
   // cout<<fail[i]<<" ";
   // }
    //cout<<endl;
    if(fail[m-1]==0){
        puts("Just a legend");
        return 0;
    }
    for(int i=fail[m-1];i>0;i=fail[i-1]){
        //cout<<i<<endl;
        if(mark[i]){
            cout<<p.substr(0,i)<<endl;
            return 0;
        }
    
    }
    
    puts("Just a legend");

    return 0;
}
