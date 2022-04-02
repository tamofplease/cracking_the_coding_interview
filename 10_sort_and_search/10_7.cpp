#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(), v.end()


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    long numberOfInts = ((long) INT32_MAX) + 1;
    vector<byte> bytes((int)numberOfInts / 8);
    string filename = "sample.txt";
    ifstream input_file(filename, ios::binary);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '" << filename << "'" << endl;
        return EXIT_FAILURE;
    }
    int number;

    while (input_file >> number){
        bytes[number / 8] |= 1 << (number % 8);
    }

    rep(i, numberOfInts / 8) {
        rep(j, numberOfInts % 8) {
            if(!(bytes[i] & (1 << j))) {
                cout << i * 8 + j << endl;
                return 0;
            }
        }
    }


    return 0;
}