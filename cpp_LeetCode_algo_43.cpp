#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
string mult(char bit, string num);
string multiply(string num1, string num2);
string Add(string num1, string num2);

int main(){
    cout << multiply("498828660196", "840477629533") << endl;
    return 0;
}


string multiply(string num1, string num2) {
    if(num1.empty() || num2.empty()) return "";
    if(num1=="0" || num2=="0") return "0";

    string ans = "0";
    string partialP;
    string tenShift = "";
    for(int i=num2.size()-1; i>=0; i--){
        partialP = mult(num2[i], num1) + tenShift;
        ans = Add(ans, partialP);
        tenShift += "0";
    }

    return ans;
}


// mult num by one bit
string mult(char bit, string num){
    string ans;
    int carry = 0;
    int tmp;
    for(int i=num.size()-1; i>=0; i--){
        tmp = (bit-'0') * (num[i]-'0');
        ans.insert(0, 1, (carry+(tmp%10))%10 + '0');
        carry = tmp/10 + (carry+(tmp%10))/10;
    }
    if(carry != 0) ans.insert(0,1,carry+'0');

    return ans;
}


string Add(string num1, string num2){
    string numA, numB;

    string zeros(abs((int)num1.size()-(int)num2.size()), '0');
    if(num1.size() < num2.size()){
        numA = zeros + num1;
        numB = num2;
    }
    else if(num1.size() > num2.size()){
        numB = zeros + num2;
        numA = num1;
    }
    else{
        numA = num1;
        numB = num2;
    }

    string ans;
    int carry = 0, tmp;
    for(int i=numA.size()-1; i>=0; i--){
        tmp = (numA[i]-'0') + (numB[i]-'0') + carry;
        ans.insert(0, 1, (tmp % 10)+'0');
        carry = tmp / 10;
    }
    if(carry != 0) ans.insert(0, 1, carry+'0');

    return ans;
}

