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
class CardsCheating{
    public:
 int numberOfShuffles(vector <int> cards, vector <int> shuffle){
vector<int> in(cards.size());
vector<int> temp(cards.size());
vector<int> v(cards.size());
for(int i=0;i<(int)cards.size();i++){
    in[i]=i;
}
int ret=0;

for(;;){
    for(int j=0;j<cards.size();j++){
   temp[j]=in[j];
    v[in[j]]=j%3;
    }
    bool f=1;
    for(int j=0;j<cards.size();j++){
       if(v[j]!=cards[j]){f=0;break;}
    }
    if(f){return ret;}
    for(int j=0;j<cards.size();j++){
    in[shuffle[j]]=temp[j];
    }
    bool br=1;
     for(int j=0;j<in.size();j++){
    if(in[j]!=j){br=0;break;}
    }
    if(br){break;}
ret++;
}
return -1;


 }
};
