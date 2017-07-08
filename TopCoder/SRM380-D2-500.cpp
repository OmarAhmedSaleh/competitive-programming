/*
 height = 1. Knight can't move, answer is 1.
 
 height = 2. Only 2 moves are available: (+2, +1) and (+2, -1). Alternate these moves while possible. Thus, the answer is min(4, (width + 1) / 2), because the knight misses only even columns and, at the same time, the "4 different moves" condition can't be hold.
 
 height >= 3. Actually, if height is > 3, we can treat it as = 3, because each (+2, +1) move can be compensated with (+2, -1) move and each (+1, +2) - with (+1, -2). There are 2 subcases:
 
 width >= 7. Knight makes all kind of a move once (he stays at (7, 1) after it) and then, alternates (+1, +2) ans (+1, -2) moves. Thus, the anser is width - 2, because only two columns are missed (by (+2, +1) and (+2, -1) moves).
 
 width < 7. Knight can't make moves of all kinds at least once each, so he is allowed to make at most 3 moves. He alternates (+1, +2) and (+1, -2) moves. The answer is min(4, width).

 */

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
const int oo=1e9;
class LameKnight{
public:
    int maxCells(int height,int width){
        if(height==1|width==1)return 1;
        if(height==2)return min(4,(width+1)/2);
        if(width<7)return min(4, width);
        return width-2;
    }
};
