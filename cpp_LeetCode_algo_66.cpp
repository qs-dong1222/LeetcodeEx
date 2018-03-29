#include <iostream>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int>& digits);

int main(){

    vector<int> digits = {9,9,9,9,9,9};

    plusOne(digits);

    for(auto each : digits){
        cout << each << " ";
    }

    return 0;
}




vector<int> plusOne(vector<int>& digits) {
    vector<int> ans;
    if(digits.empty()) return ans;

    int carry = 1;
    for(int i=digits.size()-1;i>=0;i--){
        int sum = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
        ans.insert(ans.begin(), sum);
    }

    if(carry){
        ans.insert(ans.begin(), carry);
    }

    return ans;
}













//
//vector<int> plusOne(vector<int>& digits) {
//    int carry = 1;
//    int sum = 0;
//    for(int i=digits.size()-1; i>=0; i--){
//        sum = (digits[i]+carry) % 10;
//        carry =  (digits[i]+carry) / 10;
//        digits[i] = sum;
//        if(carry==0) break;
//    }
//
//    if(carry != 0)
//        digits.insert(digits.begin(), 1, carry);
//
//    return digits;
//}
