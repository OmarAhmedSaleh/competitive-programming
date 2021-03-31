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
void printVec(const vector<int> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
void append(vector<int> &ans, int len, int n)
{
    while (len > 0 && len--)
        ans.push_back(n);
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
        int N, A, B, C;
        cin >> N >> A >> B >> C;
        int rem = N - A - B + C;
        if (C > A || C > B || A == 0 || B == 0 || C == 0 || A > N || B > N || A + B - C > N)
        {
            cout << "Case #" << TC << ": IMPOSSIBLE" << endl;
            continue;
        }
        vector<int> ans;
        append(ans, A - C, N - 1);
        if (rem > 0)
        {
            if (C > 1)
            {
                append(ans, 1, N);
                append(ans, rem, 1);
                append(ans, C - 1, N);
            }
            else
            {
                if (B - C > 0)
                {
                    append(ans, C, N);
                    append(ans, rem, 1);
                }
                else
                {
                    if (A - C > 0)
                    {
                        append(ans, rem, 1);
                        append(ans, C, N);
                    }
                    else
                    {
                        cout << "Case #" << TC << ": IMPOSSIBLE" << endl;
                        continue;
                    }
                }
            }
        }
        else
        {
            append(ans, C, N);
            append(ans, rem, 1);
        }
        append(ans, B - C, N - 1);
        cout << "Case #" << TC << ": ";
        printVec(ans);
    }
}
