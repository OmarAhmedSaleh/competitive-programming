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
//const long long OO=4e18;
//const int oo=1e9;
class LittleElephantAndPermutationDiv2{
public:

    long long getNumber(int N, int K)
    {
        int A[N];
        for (int i = 0; i < N; i++) {
            A[i] = i + 1;
        }
        long s = 0;
        do {
            int magic = 0;
            for (int i=1; i<=N; i++) {
                magic += std::max(i, A[i-1] );
            }
            if (magic >= K) {
                s++;
            }
            
        } while (next_permutation(A, A+N) );
        
        for (int i=1; i<=N; i++) {
            s *= i;
        }
        
        return s;
    }
};
