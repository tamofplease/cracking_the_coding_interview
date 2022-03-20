#include <iostream>
#include <map>

using namespace std;

/// a = 97 , z = 122
/// A = 65, Z = 90
char toSmall(char s) {
    int code = int(s);
    if(65 <= code && code <= 90) {
        return char(code + 32);
    }
    return s;
}

int main() {
    string s = "aaccabaAAZ Zb";
    bool isEven = s.length() % 2;
    map<char, int> ma;
    for(char c : s) {
        if(c == ' ') continue;
        ma[toSmall(c)]++;
    }
    for(auto const& [key, value] : ma) {
        if(value %2 != 0) {
            if(!isEven) {
                puts("No");
                return 0;
            }
            isEven = true;
        }
    }
    puts("Yes");

    return 0;
}