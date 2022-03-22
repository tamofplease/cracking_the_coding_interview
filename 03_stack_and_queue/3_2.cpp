#include <iostream>
#include <stack>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class StackWithMin {
    private:
        stack<int> minStack;
        stack<int> st;

    public:
        void push(int a) {
            if(minStack.empty()) {
                minStack.push(a);
            }
            if(minStack.top() >= a) {
                minStack.push(a);
            }
            st.push(a);
        }
        bool isEmpty() {
            return st.empty();
        }
        int top() {
            if(isEmpty()) {
                cout << "error" << endl;
                return -1;
            }
            return st.top();
        }
        void pop() {
            if(st.top() == minStack.top()) {
                minStack.pop();
            }
            st.pop();
        }
        int min() {
            return minStack.top();
        }
};

int main() {
    StackWithMin ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.pop();
    cout << ms.min() << " ";
    ms.push(0);
    cout << ms.min() << " ";
    ms.pop();
    cout << ms.min() << " ";
    cout << endl;
    
    return 0;
}