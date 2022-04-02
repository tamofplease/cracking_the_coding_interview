#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()

struct Node {
    int val;
    int leftNodes;
    Node* right;
    Node* left;

    Node(int val) : val(val), leftNodes(0), left(nullptr), right(nullptr) {};
/// 5,2,3,4,1,6
///     5 => 3
///    / \ 
// 1<=2   6=>0
/// /  \ 
// 1    3
///    / \ 
///   2.5 4

    void insert(int x) {
        if(val < x) {
            if(right == nullptr) {
                right = new Node(x);
            } else {
                right->insert(x);
            }
        } else {
            if(left == nullptr) {
                left = new Node(x);
            } else {
                left->insert(x);
            }
            leftNodes++;
        }
    }

    int getRank(int x) {
        if(val == x) return leftNodes;
        if(val < x) {
            if(right == nullptr) {
                /// could'n find target
                return -1;
            } else {
                int rightRank = right->getRank(x);
                if(rightRank == -1) return -1;
                return 1 + leftNodes + rightRank;
            }
        } else {
            if(left == nullptr) {
                /// could'n find target
                return -1;
            } else {
                int leftRank = left->getRank(x);
                if(leftRank == -1) return -1;
                return leftRank + leftNodes;
            }
        }
    }
};


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    rep(i,q) {
        string s; cin >> s;
        if(s == "insert") {

        } else {

        }
    }
    return 0;
}