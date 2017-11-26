#include <vector>
#include <iostream>

using namespace std;
vector<string> letterCombinations(string digits);

int main(){

    letterCombinations("2");

    return 0;
}


vector<string> letterCombinations(string digits) {
    vector<string> result, temp;
    if(digits.empty()) return vector<string>();
    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");   // add a seed for the initial case
    for(int i=0; i<digits.size(); i++){
        string chars = v[ digits[i]-'0' ];
        temp.clear();
        for(int j=0;j<chars.size();j++){
            for(int k=0;k<result.size();k++){
                temp.push_back( result[k] + chars[j] );
            }
        }
        swap(result, temp);
    }

    return result;
}
