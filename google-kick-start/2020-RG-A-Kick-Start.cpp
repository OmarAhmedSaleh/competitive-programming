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
vector<int> findSubStr(const string &s, const string &t)
{
    vector<int> idx;
    for (int i = 0; i < (int)s.size(); i++)
    {
        idx.push_back(i);
        for (int j = 0; j < (int)t.size(); j++)
        {
            if (i + j >= (int)s.size() || s[i + j] != t[j])
            {
                idx.pop_back();
                break;
            }
        }
    }
    return idx;
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
        int ans = 0;
        string s;
        cin >> s;
        vector<int> kIdx = findSubStr(s, "KICK");
        vector<int> sIdx = findSubStr(s, "START");
        int ptr = 0;
        for (int i = 0; i < (int)kIdx.size(); i++)
        {
            while (ptr < (int)sIdx.size() && sIdx[ptr] < kIdx[i])
            {
                ptr++;
            }
            ans += (int)sIdx.size() - ptr;
        }

        cout << "Case #" << TC << ": " << ans << endl;
    }
}
