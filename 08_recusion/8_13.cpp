#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

struct box {
    int height, width, depth;
    box(int height,int width, int depth) : height(height), width(width), depth(depth) {};

    bool operator<( const box& right) const {
        return width == right.width ? depth < right.depth : width < right.width;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<box> boxes;
    map<box, int> memo;
    rep(i,n) {
        int h,w,d; cin >> h >> w >> d;
        boxes.push_back(box(h, w, d));
    }
    sort(boxes.rbegin(), boxes.rend());
    int ans = 0;
    auto search = [&](auto f, int index, int currentDepth, int res) -> void {
        ans = max(ans, res);
        for(int i=index+1;i<n;i++) {
            if(boxes[i].depth <= currentDepth) {
                f(f, i, boxes[i].depth, res + boxes[i].height);
            } else {
                f(f, i, currentDepth, res);
            }
        }
    };
    rep(i, n) {
        search(search, i, boxes[i].depth, boxes[i].height);
    }
    cout << ans << endl;


    
    return 0;
}