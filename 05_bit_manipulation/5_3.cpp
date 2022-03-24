#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int ans = 0;
    int prev=0,work=0;
    int n; cin >> n;
    while(n > 0) {
        int bit = n&1;
        n>>=1;
        if(bit) {
            work++;
        } else {
            ans = max(ans, prev+work+1);
            prev = work;
            work = 0;
        }
    }
    ans = max(ans, prev+work+1);
    cout << ans << endl;
    return 0;
}