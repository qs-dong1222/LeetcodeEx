#include <iostream>
#include <vector>

using namespace std;
string longestCommonPrefix(vector<string>& strs) ;

int main(){
    vector<string> strs =
    //{"abcd","abc","abcde","abcde"};
    {"","c","c"};

//    for(auto eachS:strs){
//        cout << eachS << endl;
//    }

    cout << longestCommonPrefix(strs) <<endl;
    return 0;
}



/*
solution 1
*/
//string longestCommonPrefix(vector<string>& strs) {
//    if(strs.empty()){
//        return "";
//    }
//
//    if(strs.size() == 1){
//        return strs[0];
//    }
//
//    int minLen = INT_MAX;
//    for(auto eachS : strs){
//        minLen = min((int)eachS.size(), minLen);
//    }
//
//    if(minLen == 0){
//        return "";
//    }
//
//    for(int idx=0;idx<minLen;idx++){
//        for(int strIdx=0; strIdx<strs.size()-1; strIdx++){
//            if(strs[strIdx][idx] != strs[strIdx+1][idx]) {
//                return strs[strIdx].substr(0, idx);
//            }
//        }
//    }
//
//    return strs[0].substr(0, minLen);
//
//}


/*
solution 2
*/
string longestCommonPrefix(vector<string>& strs){
    string ans = "";
    if(strs.empty()) return ans;

    int idx = 0;

    while(idx<strs[0].size()){
        char ch = strs[0][idx];
        for(int i=1;i<(int)strs.size();i++){
            if(idx>=strs[i].size() || ch!=strs[i][idx]){
                return ans;
            }
        }
        ans.push_back(ch);
        idx++;
    }

    return ans;
}


/*
solution 3
*/
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return "";

    string ans = "";
    int min_size = INT_MAX;


    for(auto s : strs){
        min_size = min((int)s.size(), min_size);
    }

    for(int i=0; i<min_size; i++){
        char ch = strs[0][i];
        for(int j=1; j<strs.size(); j++){
            if(ch != strs[j][i]) return ans;
        }
        ans += ch;
    }

    return ans;
}
