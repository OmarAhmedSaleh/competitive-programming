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
        int N, ans = 0;
        cin >> N;
        vector<int> v(N), diff;
        for (int &i : v)
            cin >> i;
        for (int i = 1; i < N; i++)
            diff.push_back(v[i] - v[i - 1]);
        int seq = 0;
        for (int i = 0; i < (int)diff.size(); i++)
        {
            seq = diff[i] == diff[i - 1] ? seq + 1 : 1;
            ans = max(ans, seq + 1);
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
