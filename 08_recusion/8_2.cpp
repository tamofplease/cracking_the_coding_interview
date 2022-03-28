#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

/// input 
/// c, r
///
/// ...#.   11100
/// ....# =>12330 
/// ##...   00366

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c, r; cin >> c >> r;
    vector<string> grid(r);
    rep(i,r) cin >> grid[i];
    vector<vector<int>> memo(r, vector<int>(c, 0));
    memo[0][0] = 1;
    rep(rr, r) {
        rep(cc, c) {
            if(rr+1 < r && grid[rr+1][cc] != '#') memo[rr+1][cc] += memo[rr][cc];
            if(cc+1 < c && grid[rr][cc+1] != '#') memo[rr][cc+1] += memo[rr][cc];
        }
    }
    cout << memo[r-1][c-1] << endl;
    return 0;
}