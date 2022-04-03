#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void printLast10Lines() {
    string fileName =  "sample.txt";
    const int K = 10;
    ifstream file (fileName);
    string L[K];
    int size = 0;
    
    while(file.peek() != EOF) {
        getline(file, L[size % K]);
        size++;
    }
    for(int i=0;i<min(K, size);i++) {
        cout << L[(size + i)%K];
    }

}

int main() {
    printLast10Lines();
    return 0;
}