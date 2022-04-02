#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

void solve(vector<vector<int>>& grid) {
    

}

vector<vector<int>> input() {
    int column, row; cin >> column >> row;
    vector<vector<int>> grid(row, vector<int>(column, 0));
    rep(r, row) rep(c, col) {
        cin >> grid[r][c];
    }
    return grid;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<vector<int>> grid = input();
    solve(grid);
    return 0;
}