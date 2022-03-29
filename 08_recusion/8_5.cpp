#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

/// O(min(x, y))
int mul(int x, int y) {
    if(y == 0) return 0;
    if(x < y) swap(x, y);
    return x + mul(x, y-1);
}

map<pair<int,int>, int> memo;
int mul_with(int x, int y) {
    if(y == 0) return 0;
    if(y == 1) return x;
    if(memo.find({x,y}) != memo.end()) return memo[{x,y}];
    int divy  = y >> 1;
    memo[{x, divy}] = mul_with(x, divy);
    int res = memo[{x, divy}] << 1;
    if(y%2 == 0) return res;
    return res + x;
}

// x * y => x + x + x + ... x

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    if(n < m) swap(n, m);
    cout << mul_with(n, m) << endl;
    return 0;
}