#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


/// if find target: return pair<col, row>
/// else return pair<-1, -1>
pair<int, int> solve(vector<vector<int>>& grid, int target) {
    if(grid.size() == 0) return {-1,-1};
    int column = grid[0].size(), row = grid.size();
    return searchPartial(grid, target, {0,0}, {column-1, row-1});

}

pair<int, int> searchPartial(vector<vector<int>>& grid, int target, pair<int, int> leftTop, pair<int, int> rightBottom) {
    if(leftTop.first == rightBottom.first && leftTop.second == rightBottom.second) {
        if(grid[leftTop.first][leftTop.second] == target) return leftTop;
        return {-1, -1};
    }
    pair<int, int> endTarget = rightBottom;
    /// handle case when grid is not square
    int idx = min(leftTop.first - rightBottom.first, leftTop.second - rightBottom.second); /// 3
    if((leftTop.first - rightBottom.first) != (leftTop.second - rightBottom.second)) {
        endTarget = {idx + leftTop.first, idx + leftTop.second};
    }
    int smaller = 0, larger = idx; /// 3
    /// condition => grid[column][row] <= target
    /// smaller => always statisfy condition
    /// larget => always not satisfy condition
    
    while(larger - smaller > 1) {



    }
    
}

vector<vector<int>> input() {
    int column, row; cin >> column >> row;
    vector<vector<int>> grid(row, vector<int>(column, 0));
    rep(r, row) rep(c, column) {
        cin >> grid[r][c];
    }
    return grid;
}

vector<vector<int>> sampleInput() {
    return {
        {15, 20, 40, 85},
        {20, 35, 80, 95},
        {30, 55, 95, 105},
        {40, 80, 100, 120},
    };

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // vector<vector<int>> grid = input();
    vector<vector<int>> grid = sampleInput();
    solve(grid, 35);
    return 0;
}