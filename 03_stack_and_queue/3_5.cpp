#include <iostream>
#include <stack>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class MinPeakStack {
    private:
        stack<int> workSpace;
        stack<int> mainStack;

    public:
        void push(int val) {
            while(!mainStack.empty() && mainStack.top() < val) {
                workSpace.push(mainStack.top());
                mainStack.pop();
            }
            mainStack.push(val);
            while(!workSpace.empty()) {
                mainStack.push(workSpace.top());
                workSpace.pop();
            }
        }

        int pop() {
            int val = mainStack.top();
            mainStack.pop();
            return val;
        }

        int top() {
            return mainStack.top();
        }

        bool empty() {
            return mainStack.empty();
        }
};

int main() {
    MinPeakStack stack;
    stack.push(5);
    cout << stack.top() << " ";
    stack.push(2);
    cout << stack.top() << " ";
    stack.push(4);
    cout << stack.top() << " ";
    stack.push(1);
    cout << stack.top() << endl;
    // rep(i,10) {
    //     stack.push(10-i);
    //     cout << stack.top() << endl;
    // }
    return 0;
}