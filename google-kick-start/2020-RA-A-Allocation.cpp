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
        int N, B;
        cin >> N >> B;
        vector<int> v(N);
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int ans = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < N; i++)
        {
            if (B >= v[i])
            {
                ans++;
                B -= v[i];
            }
        }

        cout << "Case #" << TC << ": " << ans << endl;
    }
}
