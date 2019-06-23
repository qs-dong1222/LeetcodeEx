#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
int reverse(int x);

int main(){
    int in = 900000;//1534236469;
    cout << reverse(in) << endl;

    return 0;
}


/*
solution 1, convert to string
*/
//int reverse(int x) {
//    int sign = x>0? 1:-1;
//    int value = abs(x);
//
//    stringstream ss;
//
//    while(value/10){
////        cout << "x " << value << endl;
//        ss << value % 10;
//        value/=10;
//    }
//    ss << value;
//    ss >> value;
//
//    if(value>=INT_MAX || value<=INT_MIN){
//        return 0;
//    }
//    return sign*value;
//}



/*
solution 2, , convert to string
*/
//int reverse(int x) {
//    int sign = 1;
//    stringstream ss;
//    ss << x;
//    string s = ss.str();
//    ss.str("");
//    std::reverse(s.begin(), s.end());
//    if(s[s.size()-1]=='-'){
//        s.pop_back();
//        sign = -1;
//    }
//    long long tmp;
//    ss<<s;
//    ss>>tmp;
//    if(tmp>INT_MAX || tmp<INT_MIN) return 0;
//
//    return sign*stoi(s);
//}


/*
solution 3, convert to string
*/
int reverse(int x){
    int neg = x<0? true:false;

    string s = to_string(abs(x));
    std::reverse(s.begin(), s.end());
    if(neg) s = "-"+s;
    auto ans = atoll(s.c_str());
    if(ans < INT_MIN || ans > INT_MAX) return 0;
    return ans;
}



/*
solution 4, pure math solution. 只有一点需要注意, 最终结果不能超出int的最大范围
*/
int reverse(int x) {
    int sign = (x>=0)? 1:-1;
    int rem = 0;
    long int ans_abs = 0;

    x = abs(x);

    while(x>0){
        rem = x % 10;
        ans_abs = ans_abs * 10 + rem;
        if(ans_abs*sign>INT_MAX || ans_abs*sign<INT_MIN){
            return 0;
        }

        x /= 10;
    }

    return ans_abs*sign;
}
