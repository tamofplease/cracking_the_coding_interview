#include <iostream>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int getPrev(int n) {
    int work = n;
    int zero_position = 0;
    while(work&1) {
        zero_position++;
        work >>= 1;
        if(work == 0) {
            return -1;
        }
    }
    int one_position = zero_position;
    while(!(work&1)) {
        one_position++;
        work >>= 1;
    }
    int all_one = ~0; /// 1111
    /// (0001) と1111で1110を作りたい
    int zero_mask = all_one ^ (1<<zero_position);
    cout << zero_mask << endl;
    n += (1 << one_position);
    return n & zero_mask;
}

int getFollow(int n) {
    return 1;
}

int main() {
    cout << getPrev(14) << endl;
    // cout << getPrev(12) << endl;
    //// 1110 <=> 1101, 10011
    //// 1100 <=> 1010, 10001
    //// 0011 <=> 

    /// 0011101 <=> 0011011,0011110,
    /// small=> swap most right 0 to next left 1 bit;
    /// large=> swap most right 0 to next right 1 bit;
    return 0;
}