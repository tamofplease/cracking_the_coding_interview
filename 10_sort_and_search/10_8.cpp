#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    bitset<32000> bits;
    int n; cin >> n;
    rep(i,n) {
        int a; cin >> a;
        if(bits[a] == 1) {
            cout << a << endl;
        } else {
            bits[a] = 1;
        }
    }
    return 0;
}