#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // int n; cin >> n;
    // vector<int> a(n); cin >> a[i];
    ///      5  3  1  2  3
    ///       \  /  /   /
    vector<int> a = {5,3,1,2,3};
    for(int i=1;i<a.size()-1;i+=2) {
        if(a[i] > max(a[i-1], a[i+1])) continue;
        else {
            if(a[i-1] > a[i+1]) swap(a[i], a[i-1]); 
            else swap(a[i+1], a[i]);
        }
    }
    rep(i,a.size()) cout << a[i] << " ";
    cout << endl;
    return 0;
}