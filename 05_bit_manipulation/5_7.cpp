#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


int swapEvenOdd(int x) {
    return ((0xaaaaaaaa&x) >> 1) | ((0x55555555&x) << 1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    return 0;
}