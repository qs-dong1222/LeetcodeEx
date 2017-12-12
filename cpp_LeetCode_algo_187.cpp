#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>


using namespace std;
vector<string> findRepeatedDnaSequences(string s);


int main(){

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans = findRepeatedDnaSequences(s);

    for(auto each : ans){
        cout << each << endl;
    }

    return 0;
}



vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if(s.empty()) return ans;

    unordered_map<string, int> strset;

    for(int i=0;i<=(int)s.size()-10;i++){
        string newStr = s.substr(i,10);
        if(!strset.count(newStr)){
            strset[newStr] = 1;
        }
        else{
            strset[newStr]++;
            if(strset[newStr]==2){
                ans.push_back(newStr);
            }
        }
    }

    return ans;
}


//vector<string> findRepeatedDnaSequences(string s) {
//    vector<string> ans;
//    if(s.empty()) return ans;
//
//    unordered_set<string> strset;
//    unordered_set<string> ansSet;
//
//    for(int i=0;i<=(int)s.size()-10;i++){
//        string newStr = s.substr(i,10);
//        if(!strset.count(newStr)){
//            strset.insert(newStr);
//        }
//        else{
//            if(!ansSet.count(newStr))
//                ansSet.insert(newStr);
//        }
//    }
//
//    for(auto eachS:ansSet){
//        ans.push_back(eachS);
//    }
//
//    return ans;
//}
