#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


bool isPrime1(int n) {
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++) {
        if(n % i == 0) return false;
    } 
    return true;
}

bool isPrime2(int n) {
    if(n < 2) return false;
    vector<int> v(n+1, true);
    for(int i=2;i<n;i++) {
        if(!v[i]) continue;
        int tmp = 2;
        while(tmp*i <= n) {
            v[tmp*i] = false;
            tmp++;
        }
    }
    return v[n];



}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    rep(i, 100) {
        if(isPrime1(i) != isPrime2(i)) {
            cout << i << endl;
        }
    }
    return 0;
}