#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    double num; cin >> num;
    if(num > 1 || num < 0) {
        cout << "error" << endl;
        return 0;
    }
    string s = ".";
    while(num > 0) {
        if(s.length() > 32) {
            cout << "error" << endl;
            return 0;
        }
        num *= 2;
        if(num >= 1) {
            s += '1';
            num-=1;
        } else {
            s += '0';
        }
    }
    cout << s << endl;
    return 0;
}