#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    map<char, int> m;
    for(char c: s) {
        m[c]++;
    }
    vector<string> ans;
    auto rec = [&](auto f, string cur) -> void {
        if(cur.length() == s.length()) {
            ans.push_back(cur);
        }
        for(auto const& [key, val] : m) {
            if(val == 0) continue;
            m[key]--;
            f(f, cur+key);
            m[key]++;
        }
    };

    rec(rec, "");
    for(string t : ans) {
        cout << t << endl;
    }
    return 0;
}