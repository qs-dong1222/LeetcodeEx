#include <vector>
#include <iostream>

using namespace std;
vector<string> letterCombinations(string digits);

int main(){

    vector<string> ans = letterCombinations("23");
    for(auto eachS : ans){
        cout << eachS <<endl;
    }

    return 0;
}


/*
本题的难点在于如何动态的添加新字符.
其实字符串的延展可以看作是一个树状的延展. 第一个digit的所有字符都可能是树根。
我们在已有树的基础上，将新的字符添加到所有树枝上, 当前digit做完换下一个。

这个题可以看作是一个BFS的问题。每个digit代表的字符串都是下一层的可能节点, 我们要做的就是
把下一层的可能节点在当前树的基础上遍历添加一边，形成新的树。进而周而复始地运作。
*/
vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.empty()) return ans;

    vector<string> d2c =
    {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    ans.push_back(""); // 为了添加下一层节点，要先初始化最初根结点
    for(int i=0;i<(int)digits.size();i++){
        string charStr = d2c[ digits[i]-'0' ]; // d2c[2] = "abc"

        vector<string> newAns;
        for(int j=0;j<charStr.size();j++){ // 遍历下一层所有可能的节点值
            for(int k=0;k<(int)ans.size();k++){ // 为当前树添加这些下一层的可能节点
                newAns.push_back( ans[k]+charStr[j] );
            }
        }
        ans = newAns; // 更新树
    }

    return ans;
}









//vector<string> letterCombinations(string digits) {
//    vector<string> result, temp;
//    if(digits.empty()) return vector<string>();
//    static const vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//    result.push_back("");   // add a seed for the initial case
//    for(int i=0; i<digits.size(); i++){
//        string chars = v[ digits[i]-'0' ];
//        temp.clear();
//        for(int j=0;j<chars.size();j++){
//            for(int k=0;k<result.size();k++){
//                temp.push_back( result[k] + chars[j] );
//            }
//        }
//        swap(result, temp);
//    }
//
//    return result;
//}
