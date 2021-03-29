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
        int N = 26, R, C;
        cin >> R >> C;
        vector<string> wall(R);
        for (string &w : wall)
            cin >> w;
        vector<bool> placed(N, false);
        string ans = "";
        for (int it = 0; it < N; it++)
        {
            for (char let = 'A'; let <= 'Z'; let++)
            {
                if (placed[let - 'A'])
                {
                    continue;
                }
                int dep = 0;
                bool exist = false;
                for (int i = 0; i < R; i++)
                {
                    for (int j = 0; j < C; j++)
                    {
                        if (wall[i][j] == let)
                        {
                            exist = true;
                            if (i + 1 < R && wall[i + 1][j] != let && !placed[wall[i + 1][j] - 'A'])
                            {
                                dep++;
                            }
                        }
                    }
                }
                if (exist && dep == 0)
                {
                    ans += let;
                    placed[let - 'A'] = true;
                }
            }
        }
        bool bad = false;
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (!placed[wall[i][j] - 'A'])
                    ans = "-1";
            }
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
