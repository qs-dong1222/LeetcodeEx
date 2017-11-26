#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int reverse(int x);

int main(){
    int in = 1534236469;
    cout << reverse(in) << endl;

    return 0;
}

int reverse(int x) {
    int sign = x>0? 1:-1;
    int value = abs(x);

    stringstream ss;

    while(value/10){
//        cout << "x " << value << endl;
        ss << value % 10;
        value/=10;
    }
    ss << value;
    ss >> value;

    if(value>=INT_MAX || value<=INT_MIN){
        return 0;
    }
    return sign*value;
}
