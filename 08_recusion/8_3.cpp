#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


/// O(n);
int findMagicIndex(vector<int>& v) {
    rep(i,v.size()) {
        if(i == v[i]) return i;
    }
    return -1;
}
/// i 0 1 2 3 4
/// v       4 5
/// O(logN);
int findMagicIndexA(vector<int>& v) {
    int left = -1, right = v.size();
    while(right - left > 1) {
        int mid = (left + right) / 2;
        if(mid == v[mid]) return mid;
        if(mid < v[mid]) { /// e.g. 3 4
            /// make next mid smaller
            right = mid;
        } 
        if(mid > v[mid]) {
            left = mid;
        }
    }
    return -1;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    return 0;
}