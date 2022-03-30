#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


/// 0 1 2 3 4 5 6 7 8 9 10
/// 1 1 1 1 1 2 2 2 2 2 4
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int cents[4] = {1, 5, 10, 25};
    map<pair<int,int>, int> memo;
    auto dp = [&](auto f, int remain, int index) -> int {
        if(remain < 0) return 0;
        if(remain == 0) return 1;
        if(memo.find({remain, index}) != memo.end()) {
            return memo[{remain, index}];
        }
        int res = 0;
        for(int i=index;i<4;i++) {
            int cent = cents[i];
            memo[{remain-cent,i}] = f(f, remain - cent, i);
            res += memo[{remain-cent,i}];
        }
        return res;
    };
    cout << dp(dp, n, 0) << endl;
    return 0;
}