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
class solver
{
public:
    int N, K, P;
    vector<vector<int>> st, memo;
    solver(int N, int K, int P, vector<vector<int>> st)
    {
        this->N = N;
        this->K = K;
        this->P = P;
        this->st = st;
    }
    int solve()
    {
        memo.clear();
        memo.resize(N, vector<int>(P + 1, -1));
        return this->solve(0, P);
    }

private:
    int solve(int stIdx, int p)
    {
        if (stIdx == N)
        {
            return p == 0 ? 0 : -1e9;
        }
        if (p == 0)
        {
            return 0;
        }
        if (memo[stIdx][p] != -1)
        {
            return memo[stIdx][p];
        }
        int sum = 0;
        int best = solve(stIdx + 1, p);
        for (int i = 1; i <= min(p, K); i++)
        {
            sum += st[stIdx][K - i];
            best = max(best, solve(stIdx + 1, p - i) + sum);
        }
        return memo[stIdx][p] = best;
    }
};

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
        int N, K, P;
        cin >> N >> K >> P;
        vector<vector<int>> stacks(N, vector<int>(K, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < K; j++)
                cin >> stacks[i][K - j - 1];
        }
        solver s = solver(N, K, P, stacks);
        cout << "Case #" << TC << ": " << s.solve() << endl;
    }
}
