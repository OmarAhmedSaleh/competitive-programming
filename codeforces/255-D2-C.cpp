#include <algorithm>
#include <bitset>
#include <complex>
#include <cassert>
#include <deque>
#include <iostream>
#include <iomanip>
#include <istream>
#include <iterator>
#include <map>
#include <math.h>
#include <memory>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <vector>
 
using namespace std;
const int B = 1e6, N = 4001;
vector<int> idx[B + 1], v;
int memo[N][N];
int solve(int i, int j)
{
    if (memo[i][j] != -1)
        return memo[i][j];
 
    int ans = 0;
    int b = v[i] - v[j];
    int newV = v[j] + b;
    if (newV < 1)
        return 0;
    int nextIdx = upper_bound(idx[newV].begin(), idx[newV].end(), j) - idx[newV].begin();
    if (nextIdx != idx[newV].size())
        ans = solve(j, idx[newV][nextIdx]) + 1;
    return memo[i][j] = ans;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    // cin >> tc;
    tc = 1;
    for (int TC = 1; TC <= tc; TC++)
    {
        int n, best = 1;
        cin >> n;
        memset(memo, -1, sizeof(memo));
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            idx[v[i]].push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                best = max(best, solve(i, j) + 2);
        }
        cout << best << endl;
    }
}
