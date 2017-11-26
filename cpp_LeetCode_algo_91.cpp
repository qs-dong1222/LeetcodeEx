#include <iostream>
#include <vector>

using namespace std;

bool IsValid(const char& leftChar, const char& rightChar);
bool IsValid(const char& leftChar);
int foo(string& str, bool& hasZero);

int main(){
    string s = "7206";
    bool hasZero = false;
    int ans = foo(s, hasZero);
    ans += hasZero? 0:1;
    cout << ans << endl;

    return 0;
}


int foo(string& str, bool& hasZero){
    if(str.empty()){
        hasZero = true;
        return 0;
    }
    else if(str.size()==1){
        hasZero = true;
        if(str[0]=='0'){
            return 0;
        }
        else return 1;
    }
    else if(str.size()>1){
        if(str[0]=='0'){
            hasZero = true;
            return 0;
        }
        else{
            hasZero = str[1]=='0'? true:false;
        }
    }

    int count = 0;
    if(str[0]=='1'){
        count=1;
    }
    else if(str[0]=='2' && str[1]<='6'){
        count=1;
    }

    for(int i=2;i<str.size();i++){
        if(IsValid(str[i-1], str[i]))
            count++;
        if(str[i]=='0'){
            hasZero=true;
            if(!IsValid(str[i-1]))
                return 0;
            else if(i==2 && !IsValid(str[0])){
                count++;
            }
        }
    }

    return count;
}

bool IsValid(const char& leftChar){
    if(leftChar>='1'&& leftChar<='2')
        return true;
    return false;
}

bool IsValid(const char& leftChar, const char& rightChar){
    if(IsValid(leftChar)){
        if(leftChar=='1' && rightChar!='0'){
            return true;
        }
        if(leftChar=='2' && rightChar>='1' && rightChar<='6'){
            return true;
        }
    }
    return false;
}
