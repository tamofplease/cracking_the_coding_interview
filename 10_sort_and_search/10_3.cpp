#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


/// [3,4,5,0,1,2]
/// if begin < end 
    /// if(begin < mid < end) => 
    /// if(mid < begin || end < mid) => 
/// if begin > end => target
    /// if(begin > mid > end) => 
    /// if(begin < mid || mid < end)
/// return begin index of rotation
/// e.g [3,4,5,0,1,2] => return 3;
int find_rotation(int input[], int begin, int end) {
    if(input[begin] < input[end]) {
        return begin;
    }
    while(end - begin > 1) {
        /// must input[begin] > input[end]
        int mid = (end + begin) / 2;
        if(input[begin] < input[mid] && input[mid] > input[end]) {
            begin = mid;
        } else if(input[begin] > input[mid] && input[mid] < input[end]) {
            end = mid;
        } else {
            return end;
        }
    }
    return end;
}

int search(int input[], int begin, int end, int target) {
    int index = find_rotation(input, begin, end-1);
    if(input[index] <= target && target <= input[end-1]) {
        begin = index-1;
    } else {
        end = index; 
    }
    while(end - begin > 1) {
        int mid = (end + begin) / 2;
        if(input[mid] == target) return mid;
        if(input[mid] < target) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    if(input[begin] == target) return begin;
    if(input[end] == target) return end;
    return -1;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int input[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout << search(input, 0, 12, n) << endl;

    return 0;
}