#include <iostream>
#include <algorithm>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    string s = "some thing to  you";
    
    replace(s.begin(), s.end(), ' ', "%20");
    cout << s << endl;
    return 0;
}