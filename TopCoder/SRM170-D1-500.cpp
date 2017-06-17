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
class CityLink{
public:
    int p[55];
    int get(int idx){
        if(p[idx]==idx){return idx;}
        return p[idx]=get(p[idx]);
    }
    int timeTaken(vector <int> x, vector <int> y){
        int ret=0,c=0;
        vector<pair<int,pair<int,int> > >edges;
        // calculate the cost to connect city i and city j
        for(int i=0;i<(int)x.size();i++){
            for(int j=i+1;j<(int)x.size();j++){
                if(x[i]==x[j]){
                    c=abs(y[i]-y[j])/2+(abs(y[i]-y[j])&1);
                }else{
                    if(y[i]==y[j]){
                        c=abs(x[i]-x[j])/2+(abs(x[i]-x[j])&1);
                    }else{
                        c=max(abs(x[i]-x[j]),abs(y[i]-y[j]));
                    }
                }
                edges.push_back(make_pair(c,make_pair(i,j)));
            }
        }
        // Kruskal Algorithm
        for(int i=0;i<(int)x.size();i++){
            p[i]=i;
        }
        // if X.size()==1 -> edges.size() == 0 , RTE
        if(edges.size()){
            sort(edges.begin(),edges.end());
        }
        int a,b;
        for(int i=0;i<(int)edges.size();i++){
            a=get(edges[i].second.first);
            b=get(edges[i].second.second);
            if(a!=b){
                p[a]=b;
                // ans = the largest edge in MST
                ret=max(ret,edges[i].first);
            }
        }
        return ret;
    }
};
