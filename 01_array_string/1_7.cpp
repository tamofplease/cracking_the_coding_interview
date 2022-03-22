#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> v[i][j];
    /// 1,2,3    3 2 1
    /// 2,3,4 => 4 3 2
    /// 3 4 5    5 4 3
    /// (1,0), (2,1), (1,2), (0,1)
    rep(i, n/2) { //layer
        int from = i; // x position eg. 0
        int to = n - i - 1; // x position  eg. 1
        for(int j = from ; j < to ; j++) { // number
            int offset = j - from; /// 0, 1, 2... dont care about it layer
            int tmp = v[from][j]; /// top => x=>number, y => layer
            v[from][j] = v[to - offset][from];// left => x => layer, y => number
            v[to-offset][from] = v[to][to-offset]; // bottom => x => number, y => layer
            v[to][to-offset] = v[j][to]; // right => x => layer, y => number;
            v[j][to] = tmp;
        }
    }
    
    rep(i,n) {
        rep(j,n) cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}