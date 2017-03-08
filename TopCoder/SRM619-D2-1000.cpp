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
const int N=1003;
class EmployManager{
public:
    int maximumEarnings(vector<int> value, vector<string> earning){
    int ret=0;
    vector<bool> ok(value.size(),0);
    for(int i=0;i<earning.size();i++){
        for(int j=0;j<earning[i].size();j++){
                if(j==i){continue;}
            if(value[i]+value[j]<=earning[i][j]-'0'){ok[i]=ok[j]=1;}
        }

    }

            for(int i=0;i<earning.size();i++){
                int sum=0;
                int los=0;
        for(int j=0;j<earning[i].size();j++){
                    if(j==i){continue;}
            if(!ok[i]&&ok[j]){sum+=earning[i][j]-'0';}
            if(!ok[i]&&!ok[j]){los-=earning[i][j]-'0';}


        }
        if(ok[i]){continue;}
        sum-=value[i];

            if(sum>=los){ok[i]=1;}

    }




    vector<int> all,neg;
    for(int i=0;i<value.size();i++){
        if(ok[i]){ret-=value[i];all.push_back(i);continue;}
        neg.push_back(i);

    }
for(int i=0;i<all.size();i++){
    for(int j=i+1;j<all.size();j++){
        ret+=earning[all[i]][all[j]]-'0';
    }
}
for(int i=0;i<neg.size();i++){
    for(int j=i+1;j<neg.size();j++){
        ret-=earning[neg[i]][neg[j]]-'0';
    }
}
return ret;
    }


};
