#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cmath>

using namespace std;
string fractionToDecimal(int numerator, int denominator);

int main(){
    cout << fractionToDecimal(-1, -2147483648) << endl;

    return 0;
}



/*
这个题中有一些特殊的技巧, 有必要记录一下
对于求fraction部分的小数循环状态，一般用余数移位来做。
举个例子, 4/3 = 1...1, rem=1, rem/3=0.3333333
i.e 4/3 = 1.3333333, 我们关注小数部分0.333333,
为求小数，我们可以将0.33333 * 10，把小数部分一位位移到整数部分来收集。
那么就是余数*10, 即(1*10)/3 = 3.333, 收集整数3，再求余数(1*10)%3 = 1, 可以发现,
余数还是1, 换句话说, 循环小数出现时, 其根源的余数也是循环的。
我们利用这个特点, 以余数做key, 构建hashmap, 便可以记录是否有循环小数。
对于非循环小数，这些中间的余数肯定也是非循环的。

举个例子:
501/400 = 1.2525

501/400 = 1...101,
rem=101,
hash[101] = 101*10/400 = 2,
rem=101*10 % 400 = 210,
hash[210] = 210*10/400 = 5,
rem = 210*10 % 400 = 100,
hash[100] = 100*10/400 = 2,
rem = 100*10 % 400 = 200,
hash[200] = 200*10/400 = 5
rem = 200*10 % 400 = 0
可以发现，即使小数部分有看似的循环，key也是不一样的。

还有一个问题，本题是要记录循环小数的起始终止位置。那么碰到重复key的时候就是终止的地方。
之前相同key的位置就是起始的地方。那么我们可以用hash来继续当前位置。
至于每位小数的数值，我们顺序记录就可以了，不同存入hashmap。
*/
string fractionToDecimal(int numerator, int denominator){
    if(numerator==0 || denominator==0){
        return "0";
    }

    string sign = "";
    if((long long)numerator*(long long)denominator<0){
        sign = "-";
    }

    long long numeratorL = numerator<0? (long long)numerator*(-1) : (long long)numerator;
    long long denominatorL = denominator<0? (long long)denominator*(-1) : (long long)denominator;

    long long intPart = numeratorL/denominatorL;
    stringstream ss;
    ss<<intPart;
    string intStr = ss.str();

    unordered_map<int, int> rfmap;
    long long rem = numeratorL % denominatorL;

    string fracStr;
    long long pos = 0;
    while(rem != 0){
        rem *= 10;
        if(!rfmap.count(rem)){
            rfmap[rem] = pos;
            fracStr.push_back(rem/denominatorL + '0');
            rem %= denominatorL;
        }
        else{
            fracStr += ")";
            fracStr.insert(rfmap[rem], 1, '(');
            break;
        }
        pos++;
    }

    string ans;
    if(!fracStr.empty()){
        ans = sign + intStr + "." + fracStr;
    }
    else{
        ans = sign + intStr;
    }
    return ans;
}
