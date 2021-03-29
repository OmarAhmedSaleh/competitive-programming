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
        int N, K, ans = 0;
        cin >> N >> K;
        vector<int> v(N);
        for (auto &a : v)
            cin >> a;
        int ptr = 0;
        vector<int> m(K);
        for (int i = 0; i < K; i++)
            m[i] = i + 1;

        reverse(m.begin(), m.end());
        for (int i = 0; i < N; i++)
        {
            if (ptr == K || v[i] != m[ptr])
            {
                ptr = 0;
            }
            if (v[i] == m[ptr])
            {
                ptr++;
            }
            if (ptr == K)
            {
                ans++;
            }
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
