#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)


int main() {
    string s; cin >> s;
    map<char, set<char>> depend_on;
    map<char, int> insertion;
    for(char c: s) {
        insertion[c] = 0;
    }
    int m; cin >> m;
    rep(i,m) {
        char a,b; cin >> a >> b;
        insertion[a]++;
        depend_on[b].insert(a);
    }
    queue<char> q;
    for(char c:  s) {
        if(insertion[c] == 0) {
            q.push(c);
        }
    }
    vector<char> ans;
    while(!q.empty()) {
        char cur = q.front(); q.pop();
        ans.push_back(cur);
        for(char nxt : depend_on[cur]) {
            insertion[nxt]--;
            if(insertion[nxt] == 0) q.push(nxt);
        }
    }
    
    if(ans.size() == s.length()) {
        for(char a: ans) cout << a << " ";
        cout << endl;
    } else {
        cout << "No solution" << endl;
    }


    
    
    return 0;
}