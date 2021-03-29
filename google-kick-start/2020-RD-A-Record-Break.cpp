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

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++)
    {
        int ans = 0, N;
        cin >> N;
        vector<int> days(N);
        for (int &d : days)
            cin >> d;
        int mxd = -1;
        for (int i = 0; i < N; i++)
        {
            ans += (i + 1 == N || (i + 1 < N && days[i] > days[i + 1])) && mxd < days[i] ? 1 : 0;
            mxd = mxd < days[i] ? days[i] : mxd;
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
