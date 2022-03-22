#include <iostream>

using namespace std;

/// FIXME() fix
bool isSubstring(string s, string t) { /// O(min(s.len t.len))
    rep(i,min(s.length(), t.length())) {
        if(s[i] != t[i]) return false;
    }
    return true;
}

int main() {
    string s1, s2; cin >> s1 >> s2;
    if(s1.length() != s2.length()) {
        puts("No");
        return 0;
    }
    string s1s1 = s1 + s1;
    if(isSubstring(s1s1, s2)) {
        puts("Yes");
    } else {
        puts("No");
    }
    
    return 0;
}