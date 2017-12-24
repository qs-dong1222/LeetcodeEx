#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
uint32_t reverseBits(uint32_t n);

int main(){

    //cout << reverseBits(2147483648) << endl;
    cout << reverseBits(1) << endl;

    return 0;
}


uint32_t reverseBits(uint32_t n) {

    uint32_t LSB = 0;

    for(unsigned int i=0xffffffff; i>0; i>>=1){
        LSB <<= 1;
        LSB |= n & 1;
        n >>= 1;
    }

    return LSB;
}
