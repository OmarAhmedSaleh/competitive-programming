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
        vector <int> getTriple(vector <int> a, int n){
        bool ok[1001];
        memset(ok,0,sizeof(ok));
        for(int i=0;i<a.size();i++){
            ok[a[i]]=1;

        }
        vector<int> ret;

        int best=-1;

        for(int i=1;i<=1111;i++){
            if(ok[i]){continue;}
            for(int j=i;j<=1111;j++){
            if(ok[j]){continue;}
           int z=n/(i*j);
             for(int k=0;k<51;k++){
                if(z<0){break;}
                   if(ok[z]||z==0){z--;continue;}
                         int d=abs(n-(i*j*z));
                         if(best==-1||d<best){best=d;ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);
                         }
                         if(d==best&&(ret[0]>i||(ret[0]==i&&ret[1]>j)||(ret[0]==i&&ret[1]==j&&ret[2]>z))){
                        best=d;
                            ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);

                         }
                        z--;
                       // break;
                    }
                    z=n/(i*j);
                    for(int k=0;k<51;k++){
                        if(ok[z]||z==0){z++;continue;}
                         int d=abs(n-(i*j*z));
                         if(best==-1||d<best){best=d;ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);
                         }
                        if(d==best&&(ret[0]>i||(ret[0]==i&&ret[1]>j)||(ret[0]==i&&ret[1]==j&&ret[2]>z))){
                        best=d;ret.clear();
                         ret.push_back(i);
                         ret.push_back(j);
                         ret.push_back(z);

                         }

                            z++;
                    //break;

                    }




            }

        }
    sort(ret.begin(),ret.end());
        return ret;

        }

    };

