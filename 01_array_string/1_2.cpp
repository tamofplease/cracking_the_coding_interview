#include <iostream>
#include <map>

using namespace std;

int main() {
    string s,t; cin >> s >> t;
    if(s.length() != t.length()) {
        puts("No");
        return 0;
    }
    map<char, int> ma;
    for(char c : s) {
        ma[c]++;
    }
    for(char c : t) {
        if(ma.find(c) == ma.end()) {
            puts("No");
            return 0;
        }
        ma[c]--;
        if(ma[c] == 0)  ma.erase(c);
    }
    ma.empty() ? puts("Yes") : puts("No");
    return 0;
}