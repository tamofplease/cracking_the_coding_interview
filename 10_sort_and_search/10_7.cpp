#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    bitset<2147483648> bytes;
    string filename = "sample.txt";
    ifstream input_file(filename, ios::binary);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    int number;

    while (input_file >> number){
        bytes[number-1] = 1;
    }

    rep(i, 2147483648) {
        if(bytes[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }


    return 0;
}