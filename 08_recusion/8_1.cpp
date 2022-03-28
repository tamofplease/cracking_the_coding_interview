#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    map<int, int> memo;
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    auto rec = [&](auto f, int n) -> int {
        if(memo.find(n) != memo.end()) {
            return memo[n];
        }
        int res = f(f, n-1) + f(f, n-2) + f(f, n-3);
        memo[n] = res;
        return memo[n];
    };
    cout << rec(rec, n) << endl;
    return 0;
}