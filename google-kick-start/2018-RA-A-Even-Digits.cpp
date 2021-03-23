// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050edf/00000000000510ed
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
vector<int> converToVector(long long N)
{
    vector<int> v;
    while (N > 0)
    {
        int dig = N % 10;
        N /= 10;
        v.push_back(dig);
    }
    reverse(v.begin(), v.end());
    return v;
}
long long getGreater(vector<int> v)
{
    int it = 0;
    long long newN = 0;
    bool hasOddDigit = false;
    while (!hasOddDigit && it < (int)v.size())
    {
        int dig = v[it++];
        if (dig % 2 != 0)
        {
            hasOddDigit = true;
            if (dig == 9)
            {
                int dig2 = (newN % 10) + 1;
                newN /= 10;
                newN *= 10;
                newN += dig2;
                dig = 0;
            }
            else
            {
                dig++;
            }
        }
        newN *= 10;
        newN += dig;
    }
    while (it < (int)v.size())
    {
        it++;
        newN *= 10;
    }
    return hasOddDigit ? getGreater(converToVector(newN)) : newN;
}
long long getSmaller(vector<int> v)
{
    int it = 0;
    long long newN = 0;
    bool bk = false;
    while (!bk && it < (int)v.size())
    {
        int dig = v[it++];
        if (dig % 2 != 0)
        {
            dig--;
            bk = true;
        }
        newN *= 10;
        newN += dig;
    }
    while (it < (int)v.size())
    {
        newN *= 10;
        newN += 8;
        it++;
    }
    return newN;
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
        long long ans = 0, N;
        cin >> N;
        long long s = getSmaller(converToVector(N)), g = getGreater(converToVector(N));
        ans = min(abs(N - s), abs(N - g));
        // cpout << N << " " << s << " " << g << endl;
        cout << "Case #" << TC << ": " << ans << endl;
    }
}
