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
    class AvoidingProduct{
    public:
        vector<int> ret;
        int best=-1,m;
        bool check(int i,int j ,int z){
            int d=abs(m-(i*j*z));
                if(best==-1||d<best){best=d;ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);
                         }
                        if(d==best&&(ret[0]>i||(ret[0]==i&&ret[1]>j)||(ret[0]==i&&ret[1]==j&&ret[2]>z))){
                         ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);

                         }
        return i*j*z>m;
        }
        vector <int> getTriple(vector <int> a, int n){
        bool ok[1111];
        m=n;
        memset(ok,0,sizeof(ok));
        for(int i=0;i<(int)a.size();i++){
        ok[a[i]]=1;
        }
        vector<int> all;
        for(int i=1;i<=1100;i++){
            if(ok[i]){continue;}
            all.push_back(i);
        }
        for(int i=0;i<(int)all.size();i++){
            for(int j=0;j<(int)all.size();j++){
                int ll=0,hh=(int)all.size()-1;
                while(ll<=hh){
                    int mid=ll+(hh-ll)/2;
                    if(hh-ll<3){break;}
                    if(check(all[i],all[j],all[mid])){
                        hh=mid-1;
                    }else{
                    ll=mid;
                    }

                }
                while(ll<=hh){check(all[i],all[j],all[ll]);ll++;}
            }

        }

    sort(ret.begin(),ret.end());
    //cout<<best<<endl;
    //cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
        return ret;

        }

    };
