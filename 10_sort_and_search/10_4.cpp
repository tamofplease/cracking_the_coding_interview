#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int search(vector<int> v, int target) {
    if(v[0] == target) return 0;
    int end = 1;
    while(v[end] != -1) {
        end *= 2;
    }
    int begin = -1;
    cout << begin << " " << end << endl;
    while(end - begin > 1) {
        int mid = (begin + end) / 2;
        if(v[mid] == -1 || target < v[mid]) {
            end = mid;
        } else if(v[mid] < target) {
            begin = mid;
        } else if(v[mid] == target) return mid;
    }
    return begin;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> v(1000, -1);
    rep(i, 100) v[i] = i;
    cout << search(v, 86) << endl;
    return 0;
}