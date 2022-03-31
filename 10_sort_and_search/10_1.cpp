#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a[21] = {1,3,5,7,9,11,13,15,17,19};
    int b[11] = {2,4,6,8,10,12,14,16,18,20};
    int a_iter = 9, b_iter = 9;
    while(a_iter >= 0 && b_iter >= 0) {
        int a_tgt = a[a_iter], b_tgt = b[b_iter];
        int target;
        if(a_tgt > b_tgt) {
            target = a_tgt;
            a_iter--;
        } else {
            target = b_tgt;
            b_iter--;
        }
        a[a_iter + b_iter + 2] = target;
    }
    if(b_iter > 0) {
        while(b_iter >= 0) {
            a[b_iter] = b[b_iter--];
        }
    }
    rep(i,20) {
        cout << a[i] << endl;
    }
    return 0;
}