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
vector<int> notes;
int memo[10004][4];
int solve(int idx, int prev)
{
    if (idx == notes.size())
    {
        return 0;
    }
    if (memo[idx][prev] != -1)
        return memo[idx][prev];

    int ans = (int)notes.size() + 1;
    for (int i = 0; i < 4; i++)
    {
        int ex = notes[idx] > notes[idx - 1] && i <= prev ? 1 : 0;
        ex = notes[idx] < notes[idx - 1] && i >= prev ? 1 : ex;
        ex = notes[idx] == notes[idx - 1] && i != prev ? 1 : ex;
        ans = min(ans, solve(idx + 1, i) + ex);
    }
    return memo[idx][prev] = ans;
}

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
        int N;
        cin >> N;
        notes.clear();
        notes.resize(N);
        for (int &n : notes)
            cin >> n;
        memset(memo, -1, sizeof(memo));
        int ans = N + 1;
        for (int i = 0; i < 4; i++)
        {
            ans = min(ans, solve(1, i));
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
