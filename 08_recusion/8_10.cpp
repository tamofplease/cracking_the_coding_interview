#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

void show(vector<string>& figure) {
    if(figure.size() == 0) return;
    rep(r,figure.size()) {
        rep(c, figure[0].size()) {
            cout << figure[r][c];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int row, col; cin >> row >> col;
    vector<string> figure(row);
    rep(r, row) cin >> figure[r];
    char c; cin >> c;
    int tr, tc; cin >> tr >> tc;
    char from = figure[tr][tc];
    int delta[5] = {0,-1,0,1,0};
    auto reFill = [&](auto f, int cr, int cc) -> void {
        figure[cr][cc] = c;
        for(int x=0;x<4;x++) {
            int nr = cr + delta[x];
            for(int y=1;y<5;y++) {
                int nc = cc + delta[y];
                if(0 <= nr && nr < row && 0 <= nc && nc < col) {
                    if(figure[nr][nc] == from) f(f, nr, nc);
                }
            }
        }
    };
    if(figure[tr][tc] == c) {
        show(figure);
        return 0;
    }
    reFill(reFill, tr, tc);
    show(figure);
    return 0;
}