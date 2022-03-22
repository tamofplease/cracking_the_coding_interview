#include <iostream>

using namespace std;

int main() {
    string s, t; cin >> s >> t;
    if(s.length() > t.length()+1 || s.length() < t.length()-1) {
        puts("No");
        return 0;
    }

    bool canFix = true;
    /// replace
    if(s.length() == t.length()) {
        for(int i=0;i<s.length();i++) {
            if(s[i] != t[i])  {
                if(!canFix) {
                    puts("No");
                    return 0;
                }
                canFix = false;
            }
        }
        puts("Yes");
        return 0;
    }

    /// delete
    if(s.length() > t.length()) {
        for(int i=0;i<s.length();i++) {
            int j = i - int(!canFix); /// if after delete operation
            if(s[i] != t[j])  {
                if(!canFix) {
                    puts("No");
                    return 0;
                }
                canFix = false;
            }
        }
        puts("Yes");
        return 0;
    }

    /// intert
    for(int i=0;i<s.length();i++) {
        int j = i + (int(!canFix));
        if(s[i+int(!canFix)] != t[i])  {
            if(!canFix) {
                puts("No");
                return 0;
            }
            canFix = false;
        }
    }
    puts("Yes");
    return 0;
}