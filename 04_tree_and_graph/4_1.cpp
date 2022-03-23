#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> to(n);
    int start, goal; cin >> start >> goal;
    start--; goal--;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
    }
    vector<bool> memo(n, false);
    queue<int> q;
    q.push(start);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        memo[cur] = true;
        if(cur == goal) {
            puts("Yes");
            return 0;
        }
        for(int nxt : to[cur]) {
            if(!memo[nxt]) {
                q.push(nxt);
            }
        }
    }
    puts("No");
    return 0;
}