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
int cntLShape(vector<vector<int>> &cnt, vector<vector<int>> &grid, int R, int C)
{
    int ans = 0;
    for (int c = 0; c < C; c++)
    {
        int seq = 0;
        for (int r = 0; r < R; r++)
        {
            seq = grid[r][c] == 1 ? seq + 1 : 0;
            int mn = min(seq, cnt[r][c]);
            int mx = max(seq, cnt[r][c]);
            if (mn < 2)
            {
                continue;
            }
            ans += min(mx / 2 - 1, mn - 1) + (mn / 2 - 1);
        }
    }
    for (int c = 0; c < C; c++)
    {
        int seq = 0;
        for (int r = R - 1; r > -1; r--)
        {
            seq = grid[r][c] == 1 ? seq + 1 : 0;
            int mn = min(seq, cnt[r][c]);
            int mx = max(seq, cnt[r][c]);
            if (mn < 2)
            {
                continue;
            }

            ans += min(mx / 2 - 1, mn - 1) + (mn / 2 - 1);
        }
    }
    return ans;
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
        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C, 0));
        vector<vector<int>> cnt(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < R; i++)
        {
            int seq = 0;
            for (int j = C - 1; j > -1; j--)
            {
                seq = grid[i][j] == 1 ? seq + 1 : 0;
                cnt[i][j] = seq;
            }
        }
        int ans = cntLShape(cnt, grid, R, C);

        for (int i = 0; i < R; i++)
        {
            int seq = 0;
            for (int j = 0; j < C; j++)
            {
                cnt[i][j] = 0;
                seq = grid[i][j] == 1 ? seq + 1 : 0;
                cnt[i][j] = seq;
            }
        }

        ans += cntLShape(cnt, grid, R, C);

        cout << "Case #" << TC << ": " << ans << endl;
    }
}
