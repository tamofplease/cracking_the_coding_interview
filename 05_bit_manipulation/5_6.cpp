#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int getBitDiff(int a, int b) {
    int res = 0;
    while(a!=0||b!=0) {
        res += (a&1^b&1);
        a >>= 1;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    cout << getBitDiff(n,m) << endl;
    return 0;
}