#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

vector<vector<int>> ans;

/// O(n*2^n*)
void getPart(vector<int>& v, vector<int> work, int cur) {
    if(cur == v.size()) return;
    vector<int> pw = work;
    pw.push_back(v[cur]);
    ans.push_back(pw);
    getPart(v, pw, cur+1);
    getPart(v, work, cur+1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v1(n);
    rep(i,n) cin >> v1[i];
    vector<int> w;
    ans.push_back(vector<int>());
    getPart(v1, w, 0);
    rep(i, ans.size()) {
        rep(j, ans[i].size()) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}