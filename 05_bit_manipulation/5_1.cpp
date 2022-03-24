#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)



int main() {
    int n,m; cin >> n >> m;/// 10000000000, 10011
    int i,j; cin >> i >> j; // i = 2, j = 6
    /// 1. create clear mask which clear i from j
    /// 2. create mask which all 1 and i to j is m
    /// 3. n & 1 => i to j is 0
    int allOnes = ~0;
    //// 111111000000
    int right = allOnes << (j+1);

    /// 0000000011
    int left = (1 << i) - 1;
    int clear_mask = right | left;
    int n_clear = clear_mask & n;
    m <<= i;
    n = n_clear | m;
    cout << n << endl;
    return 0;
}