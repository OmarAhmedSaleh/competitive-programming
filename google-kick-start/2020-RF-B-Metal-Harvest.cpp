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
        int N, X, ans = 0;
        cin >> N >> X;
        vector<pair<int, int>> V(N);
        for (auto &v : V)
            cin >> v.first >> v.second;
        sort(V.begin(), V.end());
        int curPos = 0;
        for (auto v : V)
        {
            curPos = max(curPos, v.first);
            if (curPos >= v.second)
                continue;
            int rNeeded = ((v.second - curPos) / X) + ((v.second - curPos) % X != 0 ? 1 : 0);
            ans += rNeeded;
            curPos += rNeeded * X;
        }
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
