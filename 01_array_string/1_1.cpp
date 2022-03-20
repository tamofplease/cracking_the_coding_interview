#include <iostream>

using namespace std;

int main() {
    string s; cin >> s;
    sort(s.begin(), s.end());
    for(int i=0;i<s.length()-1;i++) {
        if(s[i] == s[i+1]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}