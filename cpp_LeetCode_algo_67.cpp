#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;
string addBinary(string a, string b);
char Sum2Bits(const char& bit1, const char& bit2, char& carry);

int main(){

    string a = "1";
    string b = "111";

    cout << addBinary(a, b) << endl;

    return 0;
}



string addBinary(string a, string b) {
    string ans="";
    int sizeDiff = abs(a.size()-b.size());
    if(a.size() < b.size())
        for(int i=1; i<=sizeDiff; i++) a.insert(0,1,'0'); //a = '0'+a;
    else if(b.size() < a.size())
        for(int i=1; i<=sizeDiff; i++) b.insert(0,1,'0'); //b = '0'+b;

    int carry=0;
    int tmp;
    for(int i=a.size()-1; i>=0; i--){
        tmp = (a[i]-'0') + (b[i]-'0') + carry;
        carry = tmp/2;
        ans.insert(0, 1, (tmp%2)+'0');
    }
    if(carry != 0)
        ans.insert(0, 1, carry+'0');

    return ans;
}


//char Sum2Bits(const char& bit1, const char& bit2, char& carry){
//    int bit_1 = bit1-'0';
//    int bit_2 = bit2-'0';
//    int carry_ = carry-'0';
//    char sum = (bit_1^bit_2^carry_) + '0';
//    carry = ((bit_1&bit_2) | ((bit_1|bit_2)&carry_)) + '0';
//    return sum;
//}
