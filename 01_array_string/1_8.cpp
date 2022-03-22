#include <iostream>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m, 0));
    rep(i,n) rep(j,m) {
        cin >> table[i][j];
        if(table[i][j] == 0) {
            table[i][0] = 0;
            table[0][j] = 0;
        }
    }
    rep(i,n) {
        if(table[i][0] == 0) {
            rep(j,m) table[i][j] = 0;
        }
    }
    rep(j,m) {
        if(table[0][j] == 0) {
            rep(i,n) table[i][j] = 0;
        }
    }
    rep(i,n) {
        rep(j,m) cout << table[i][j] << " ";
        cout << endl;
    }
    return 0;
}