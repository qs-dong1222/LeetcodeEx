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
���������һЩ����ļ���, �б�Ҫ��¼һ��
������fraction���ֵ�С��ѭ��״̬��һ����������λ������
�ٸ�����, 4/3 = 1...1, rem=1, rem/3=0.3333333
i.e 4/3 = 1.3333333, ���ǹ�עС������0.333333,
Ϊ��С�������ǿ��Խ�0.33333 * 10����С������һλλ�Ƶ������������ռ���
��ô��������*10, ��(1*10)/3 = 3.333, �ռ�����3����������(1*10)%3 = 1, ���Է���,
��������1, ���仰˵, ѭ��С������ʱ, ���Դ������Ҳ��ѭ���ġ�
������������ص�, ��������key, ����hashmap, ����Լ�¼�Ƿ���ѭ��С����
���ڷ�ѭ��С������Щ�м�������϶�Ҳ�Ƿ�ѭ���ġ�

�ٸ�����:
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
���Է��֣���ʹС�������п��Ƶ�ѭ����keyҲ�ǲ�һ���ġ�

����һ�����⣬������Ҫ��¼ѭ��С������ʼ��ֹλ�á���ô�����ظ�key��ʱ�������ֹ�ĵط���
֮ǰ��ͬkey��λ�þ�����ʼ�ĵط�����ô���ǿ�����hash��������ǰλ�á�
����ÿλС������ֵ������˳���¼�Ϳ����ˣ���ͬ����hashmap��
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
