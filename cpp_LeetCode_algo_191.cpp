#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
int hammingWeight(uint32_t n);


int main(){

    cout << hammingWeight(11) << endl;

    return 0;
}


int hammingWeight(uint32_t n) {
    if(n==0) return n;

    int ans = 0;
    while(n>0){
        ans += n&1;
        n >>= 1;
    }

    return ans;
}
