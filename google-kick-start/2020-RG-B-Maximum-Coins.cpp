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
        long long ans = 0;
        int N;
        cin >> N;
        vector<vector<long long>> g(N, vector<long long>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> g[i][j];
                if (i > 0 && j > 0)
                {
                    g[i][j] += g[i - 1][j - 1];
                }
                ans = g[i][j] > ans ? g[i][j] : ans;
            }
        }

        cout << "Case #" << TC << ": " << ans << endl;
    }
}
