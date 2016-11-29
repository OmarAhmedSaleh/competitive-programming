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
#include <queue>

using namespace std;
const int N=1000006;
class NetworkXMessageRecovery{
public:
string recover(vector <string> messages){
int ok[333];
memset(ok,-1,sizeof(ok));
string ans="";
vector<char> e[333];
for(int i=0;i<messages.size();i++){
    for(int j=0;j<messages[i].size();j++){
            ok[(int)messages[i][j]]=0;
        for(int k=j-1;k>-1;k--){
            e[(int)messages[i][k]].push_back(messages[i][j]);
        }
    }
}
for(int i=0;i<333;i++){
    for(int j=0;j<e[i].size();j++){
        ok[(int)e[i][j]]++;

    }

}
set<char> pq;

for(int i=0;i<333;i++){
if(ok[i]==0){
    pq.insert((char)i);

}

}
while(!pq.empty()){
    char c=*pq.begin();
    pq.erase(pq.begin());
    ans+=c;
    for(int i=0;i<e[(int)c].size();i++){
        char ww=e[(int)c][i];
        ok[(int)ww]--;
        if(!ok[(int)ww]){pq.insert(ww);}

    }


}
    return ans;
     }
};
