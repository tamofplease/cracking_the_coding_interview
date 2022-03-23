#include <iostream>
#include <stack>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class MyQueue {
    private:
        stack<int> st1;
        stack<int> st2;
    public:
        int pop() {
            int val = st1.top();
            st1.pop();
            return val;
        }

        int front() {
            return st1.top();
        }

        void push(int val) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(val);
            while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }
        }

        bool empty() {
            return st1.empty();
        }
};

int main() {
    MyQueue q;
    rep(i,10) {
        q.push(i);
    }
    rep(i,10) {
        cout << q.pop() << endl;
    }
    
    return 0;
}