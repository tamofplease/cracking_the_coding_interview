#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

struct Tower {
    string name;
    int height = 0;
    stack<int> st;

    int pop() {
        int val = st.top();
        height--;
        st.pop();
        return val;
    }

    void setName(string s) {
        name = s;
    }

    void push(int val) {
        height++;
        st.push(val);
    }

    bool empty() {
        return height==0;
    }
};

void moveTower(Tower& from, Tower& to) {
    int val = from.pop();
    cout << "move " << val << " from " << from.name << " to " << to.name << endl;
    to.push(val);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    Tower from, to, work;
    from.setName("left");
    work.setName("center");
    to.setName("right");
    rep(i,n) {
        from.push(n-i);
    }


    auto hanoi = [&](auto f, Tower& from, Tower& work, Tower& to, int number) {
        if(number == 0) return;
        f(f, from, to, work, number-1);
        moveTower(from, to);
        f(f, work, from, to, number-1);
    };

    hanoi(hanoi, from, work, to, n);

    return 0;
}