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
bool valid(const vector<long long> &x, const long long startDay, const long long D)
{
    long long currentDay = startDay;
    for (int i = 0; i < (int)x.size(); i++)
    {
        currentDay = (currentDay / x[i] + (currentDay % x[i] != 0 ? 1 : 0)) * x[i];
    }
    return currentDay <= D;
}
long long binarySearch(const vector<long long> &x, const long long D)
{
    long long low = 1, high = D, ans = 1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (valid(x, mid, D))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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
        int N;
        long long ans = 1, D;
        cin >> N >> D;
        vector<long long> x(N);
        for (int i = 0; i < N; i++)
            cin >> x[i];
        cout << "Case #" << TC << ": " << binarySearch(x, D) << endl;
    }
}
