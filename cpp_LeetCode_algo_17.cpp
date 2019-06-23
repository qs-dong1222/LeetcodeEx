#include <vector>
#include <iostream>

using namespace std;
vector<string> letterCombinations(string digits);
void dfs(string& digits, vector<string>& d2c, int idx, vector<string>& ans, string& curr_str);

int main(){

    vector<string> ans = letterCombinations("23");
    for(auto eachS : ans){
        cout << eachS <<endl;
    }

    return 0;
}


/*
    solution: BFS
������ѵ�������ζ�̬��������ַ�.
��ʵ�ַ�������չ���Կ�����һ����״����չ. ��һ��digit�������ַ����Ƕ�����������
���������������Ļ����ϣ����µ��ַ���ӵ�����������, ��ǰdigit���껻��һ����

�������Կ�����һ��BFS�����⡣ÿ��digit������ַ���������һ��Ŀ��ܽڵ�, ����Ҫ���ľ���
����һ��Ŀ��ܽڵ��ڵ�ǰ���Ļ����ϱ������һ�ߣ��γ��µ����������ܶ���ʼ��������
*/
vector<string> letterCombinations(string digits){
    vector<string> ans;
    if(digits.empty()) return ans;

    vector<string> d2c =
    {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    ans.push_back(""); // Ϊ�������һ��ڵ㣬Ҫ�ȳ�ʼ����������
    for(int i=0;i<(int)digits.size();i++){
        string charStr = d2c[ digits[i]-'0' ]; // d2c[2] = "abc"

        vector<string> newAns;
        for(int j=0;j<charStr.size();j++){ // ������һ�����п��ܵĽڵ�ֵ
            for(int k=0;k<(int)ans.size();k++){ // ����ǰ�ڵ�ֵ��ӵ���һ�����еĽ����
                newAns.push_back( ans[k]+charStr[j] );
            }
        }
        ans = newAns; // ������
    }

    return ans;
}



/*
 BFS����һ��д��
*/
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



/*
 solution: DFS
*/
//vector<string> letterCombinations(string digits){
//    vector<string> ans;
//    if(digits.empty()) return ans;
//
//    vector<string> d2c =
//    {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//
//    string curr_str = "";
//
//    dfs(digits, d2c, 0, ans, curr_str);
//
//    return ans;
//}
//
//void dfs(string& digits, vector<string>& d2c, int idx, vector<string>& ans, string& curr_str){
//    if(idx == digits.size()){
//        ans.push_back(curr_str);
//        return;
//    }
//
//    string chars = d2c[digits[idx] - '0'];
//    for(int i=0; i<chars.size(); i++){
//        curr_str.push_back(chars[i]);
//        dfs(digits, d2c, idx+1, ans, curr_str);
//        curr_str.pop_back();
//    }
//}
