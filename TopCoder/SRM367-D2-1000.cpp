#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
class ProgrammingDevice{
public:
    int minPackets(vector <int> offset, vector <int> size, int maxData){
    int ret=0;
    long long cur=0;
    vector<pair<int,int> > v;
    for(int i=0;i<offset.size();i++){
        v.push_back(make_pair(offset[i],size[i]));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<offset.size();i++){
      offset[i]=v[i].first;
      size[i]=v[i].second;
      }
    for(int i=0;i<offset.size();i++){
        if(offset[i]>cur){cur=offset[i];}
        if(cur>=offset[i]&&cur<=(offset[i]+size[i])-1){
            long long d=(offset[i]+size[i])-1;
            d-=cur;
            d++;
            ret+=(d/maxData)+(d%maxData!=0);
            cur+=((d/maxData)+(d%maxData!=0))*maxData;
        }


    }


    return ret;
    }

};
