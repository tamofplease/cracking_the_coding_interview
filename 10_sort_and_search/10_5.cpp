#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

int search(vector<string>& strings, string target, int first, int last) {
    if(first > last) return -1;
    int mid = (first + last) / 2;

    if(strings[mid].empty()) {
        int left = mid - 1;
        int right = mid + 1;
        while(true) {
            if(left < first && right > last) {
                return -1;
            } else if(right <= last &&  strings[right].length() != 0) {
                right = mid;
                break;
            } else if(left <= first && strings[left].length() != 0) {
                left = mid;
                break;
            }
            left--;
            right++;
        }
    }
    if(strings[mid] == target) {
        return mid;
    } else if(strings[mid] < target) {
        return search(strings, target, mid+1, last);
    } else {
        return search(strings, target, first, mid-1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> strings;
    string target; cin >> target;
    rep(i,n) cin >> strings[i];

    cout << search(strings, target, 0, n-1) << endl;
    return 0;
}