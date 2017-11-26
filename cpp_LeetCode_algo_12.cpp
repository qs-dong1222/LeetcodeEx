#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string Convert2Roman(char numCh, char one, char five, char ten);
string intToRoman(int num);

int main(){

    cout << intToRoman(2999) << endl;

    return 0;
}

string Convert2Roman(char numCh, char one, char five, char ten){
    stringstream ss;
    int num = numCh - '0';
    if(num==0){
        return "";
    }

    if(num>=1 && num<=3){
        for(int i=0;i<num;i++){
            ss<<one;
        }
    }
    else if(num==4){
        ss<<one<<five;
    }
    else if(num==5){
        ss<<five;
    }
    else if(num>=6 && num<=8){
        ss<<five;
        for(int i=0;i<num-5;i++){
            ss<<one;
        }
    }
    else{
        ss<<one<<ten;
    }

    return ss.str();
}

string intToRoman(int num) {
    stringstream ss;
    ss<<num;
    string Arabic = ss.str();
    string zeros;
    for(int i=0;i<4-Arabic.size();i++){
        zeros += '0';
    }
    Arabic = zeros + Arabic;

    return Convert2Roman(Arabic[0], 'M', '~', '~')
            + Convert2Roman(Arabic[1], 'C', 'D', 'M')
            + Convert2Roman(Arabic[2], 'X', 'L', 'C')
            + Convert2Roman(Arabic[3], 'I', 'V', 'X');
}
