#include <iostream>
#include <vector>

using namespace std;
string longestCommonPrefix(vector<string>& strs) ;

int main(){
    vector<string> strs = {"c","c"};

//    for(auto eachS:strs){
//        cout << eachS << endl;
//    }

    cout << longestCommonPrefix(strs) <<endl;
    return 0;
}




string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()){
        return "";
    }

    if(strs.size() == 1){
        return strs[0];
    }

    int minLen = INT_MAX;
    for(auto eachS : strs){
        minLen = min((int)eachS.size(), minLen);
    }

    if(minLen == 0){
        return "";
    }

    for(int idx=0;idx<minLen;idx++){
        for(int strIdx=0; strIdx<strs.size()-1; strIdx++){
            if(strs[strIdx][idx] != strs[strIdx+1][idx]) {
                return strs[strIdx].substr(0, idx);
            }
        }
    }

    return strs[0].substr(0, minLen);

}



