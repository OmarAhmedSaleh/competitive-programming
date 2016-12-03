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
class 	MatrixGame{
public:
    vector <string> getMinimal(vector <string> matrix){
    vector<string> ret=matrix;
    vector<int> col;
    vector<pair<int,int> >row;
    vector<vector<int> > allc;
    for(int i=0;i<matrix[0].size();i++){col.push_back(i);}
       do{
        allc.push_back(col);

    }while(next_permutation(col.begin(),col.end()));



    for(int i=0;i<allc.size();i++){
    row.clear();
    for(int j=0;j<matrix.size();j++){
                int sum=0;
    for(int cc=0;cc<allc[i].size();cc++){
    if(matrix[j][allc[i][cc]]=='1'){break;}
        sum++;
                }
    row.push_back(make_pair(sum,j));

            }

sort(row.rbegin(),row.rend());


vector<string> temp=matrix;
for(int rr=0;rr<matrix.size();rr++){
    for(int cc=0;cc<matrix[0].size();cc++){
        temp[rr][cc]=matrix[row[rr].second][allc[i][cc]];

    }

}
for(int rr=0;rr<matrix.size();rr++){
    for(int rrr=rr+1;rrr<matrix.size();rrr++){
        for(int cc=0;cc<matrix[rr].size();cc++){
            if(temp[rr][cc]=='1'&&temp[rrr][cc]=='0'){swap(temp[rr],temp[rrr]);break;}
            if(temp[rrr][cc]=='1'&&temp[rr][cc]=='0'){break;}

        }

    }

}
int ok=-1;
for(int rr=0;ok==-1&&rr<matrix.size();rr++){
    for(int cc=0;ok==-1&&cc<matrix[0].size();cc++){
        if(ret[rr][cc]=='0'&&temp[rr][cc]=='1'){ok=0;break;}
        if(ret[rr][cc]=='1'&&temp[rr][cc]=='0'){ok=1;swap(ret,temp);break;}

    }

}


    }



    return ret;
}

};
