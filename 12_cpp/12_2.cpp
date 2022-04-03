#include <iostream>


void reverseChar(char *str) {
    char *end = str;
    char tmp ;
    if(str) {
        while(*end) {
            end++;
        }
        end--;

        while(str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main() {
    char *c = "something";
    reverseChar(c);
    // std::cout << *c << std::endl;
    return 0;
}