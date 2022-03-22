#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class SetOfStacks {
    private:
        vector<stack<int>> stacks;
        int maxNumber = 3;
        int currentNumber;
    public:
        void pop() {
            if(currentNumber == 1) {
                stacks[stacks.size()-1].pop();
                stacks.erase(stacks.begin() + stacks.size()-1);
                if(stacks.size() != 0) {
                    currentNumber = 3;
                } else {
                    currentNumber = 0;
                }
            } else {
                stacks[stacks.size()-1].pop();
                currentNumber--;
            }
        }
        void push(int val) {
            if(currentNumber == 0) {
                stack<int> newStack;
                newStack.push(val);
                stacks.push_back(newStack);
                currentNumbers++;
                return;
            }
            if(currentNumber == maxNumber) {
                stack<int> newStack;
                newStack.push(val);
                stacks.push_back(newStack);
                currentNumber = 1;
                return;
            } 
            stacks[stacks.size()-1].push(val);
            currentNumber++;
        }

        int top() {
            if(stacks.size() == 0) return -1;
            return stacks[stacks.size()-1].top();
        }
};

int main() {
    SetOfStacks st;
    rep(i, 10) {
        st.push(i);
    }

    rep(i,10) {
        cout << st.top() << endl;
        st.pop();
    }
    
    return 0;
}