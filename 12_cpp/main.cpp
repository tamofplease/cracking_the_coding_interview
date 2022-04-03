#include <iostream>
#include <set>

using namespace std;


/// O(se * )
bool canSegmentString(string s, set<string> se) {
    if(s.length() == 0) return true;
    for(string tgt : se) {
        if(s.length() >= tgt.length() && s.substr(0, tgt.length()) == tgt) {
            if( canSegmentString(s.substr(tgt.length(), s.length()-tgt.length()), se) ) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    set<string> se = {"hello", "hell", "on", "now"};
    if(canSegmentString("hellonow", se)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}