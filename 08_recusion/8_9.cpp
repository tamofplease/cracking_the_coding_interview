#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()
/// 1 => ()
/// 2 => ()(), (())
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> ans;
    auto capt = [&](auto f, int left, int right, string cur) -> void {
        if(right == 0 && left == 0) {
            ans.push_back(cur);
            return;
        }
        if(left > 0) {
            f(f, left-1, right, cur+'(');
        }
        if (right > left)
            f(f, left, right-1, cur+')');
    };

    capt(capt, n, n, "");
    for(string s: ans) {
        cout << s << endl;
    }
    return 0;
}