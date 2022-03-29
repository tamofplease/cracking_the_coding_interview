#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    vector<string> ans;
    auto rec = [&](auto f, int index, string cur) {
        if(s.length() == index) {
            ans.push_back(cur);
            return;
        }
        char c = s[index];
        for(int i=0;i<=cur.length();i++) {
            string nxt = cur;
            nxt.insert(i, 1, c);
            f(f, index+1, nxt);
        }
    };
    string c;
    c.push_back(s[0]);
    rec(rec, 1, c);
    cout << ans.size() << endl;
    return 0;
}