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
        int N, X;
        cin >> N >> X;
        vector<int> V(N);
        for (int &v : V)
            cin >> v;
        vector<pair<int, int>> order;
        for (int i = 0; i < N; i++)
            order.push_back({(V[i] / X + (V[i] % X != 0 ? 1 : 0)), i});

        sort(order.begin(), order.end());
        vector<int> ans;
        for (pair<int, int> p : order)
            ans.push_back(p.second + 1);
        cout << "Case #" << TC << ": ";
        printVec(ans);
    }
}
