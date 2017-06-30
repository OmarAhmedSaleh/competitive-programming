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
class ShortestPathWithMagic{
public:
    double d[55][55];
    int p[55];
    vector<int> v;
    void get(int idx){
        if(p[idx]==-1){
            v.push_back(idx);
            return;
        }
        get(p[idx]);
        v.push_back(idx);
    }
    double getTime(vector <string> dist, int k){
        double ret=0;
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<=k;j++){
                d[i][j]=1e9;
            }
        }
        d[0][k]=0;
        priority_queue<pair<double,pair<int,int> > > pq;
        p[0]=-1;
        pq.push(make_pair(0,make_pair(0,k)));
        while(!pq.empty()){
            int idx=pq.top().second.first;
            double ds=pq.top().first;
            int kk=pq.top().second.second;
            ds*=-1;
            pq.pop();
            if(d[idx][kk]<ds){continue;}
            for(int i=0;i<dist.size();i++){
            int w=dist[idx][i]-'0';
                if(d[i][kk]>d[idx][kk]+w){
                    d[i][kk]=d[idx][kk]+w;
                    pq.push(make_pair(-d[i][kk],make_pair(i,kk)));
                    p[i]=idx;
                }
                if(kk&&d[i][kk-1]>d[idx][kk]+(double)w/2){
                    d[i][kk-1]=d[idx][kk]+(double)w/2;
                    pq.push(make_pair(-d[i][kk-1],make_pair(i,kk-1)));
                    p[i]=idx;
                    
                }
            }
        }
        ret=1e9;
        for(int i=0;i<=k;i++){
            ret=min(ret,d[1][i]);
        }
        return ret;
    }
};
