#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;


string solve(string s) {
    string ans;
    char prev;
    int cnt = 0;
    bool isLastAppend;
    for(char c : s) {
        if(prev == c) {
            cnt++;
        } else {
            if(!prev) {
                prev = c;
                cnt = 1;
                continue;
            }
            ans += prev;
            ans += to_string(cnt);
            prev = c;
            cnt = 1;
        }
        isLastAppend = (prev!=c);
    }
    if(!isLastAppend) {
        ans += prev;
        ans += to_string(cnt);
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    string ans = solve(s);
    if(ans.length() < s.length()) {
        cout << ans << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}