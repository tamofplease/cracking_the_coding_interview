#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

class ThreeStack {
    private:
        int stackArray[300];
        int stackPointers[3] = {0,1,2};

    public:
        ThreeStack() {
            // stackPointers = [0,1,2];
        }
        void pushToStack(int stackNumber, int value) {
            stackArray[stackPointers[stackNumber]] = value;
            stackPointers[stackNumber]+=3;
        }
        int popFromStack(int stackNumber) {
            stackPointers[stackNumber]-=3;
            return stackArray[(3 + stackPointers[stackNumber])];
        }
        int front(int stackNumber) {
            return stackArray[stackPointers[stackNumber]];
        }
        bool isEmpty(int stackNumber) {
            return stackPointers[stackNumber] == stackNumber;
        }
};

int main() {
    ThreeStack stacks;
    stacks.pushToStack(0, 3);
    stacks.pushToStack(0,5);
    stacks.pushToStack(0,5);
    while(!stacks.isEmpty(0)) {
        cout << stacks.popFromStack(0) << endl;
    }
    return 0;
}