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
        int ans = 2e9;
        int N, P;
        cin >> N >> P;
        vector<int> s(N);
        for (int i = 0; i < N; i++)
            cin >> s[i];
        if (P == 1)
            ans = 0;
        sort(s.begin(), s.end());
        int ptr = 0, cost = 0;
        for (int i = 1; i < N; i++)
        {
            int len = (i - ptr) + 1;
            cost += (len - 1) * (s[i] - s[i - 1]);
            while (len > P)
            {
                cost -= s[i] - s[ptr++];
                len--;
            }
            if (len == P)
                ans = min(ans, cost);
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
