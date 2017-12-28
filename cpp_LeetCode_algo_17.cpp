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
������ѵ�������ζ�̬��������ַ�.
��ʵ�ַ�������չ���Կ�����һ����״����չ. ��һ��digit�������ַ���������������
�������������Ļ����ϣ����µ��ַ���ӵ�������֦��, ��ǰdigit���껻��һ����

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
            for(int k=0;k<(int)ans.size();k++){ // Ϊ��ǰ�������Щ��һ��Ŀ��ܽڵ�
                newAns.push_back( ans[k]+charStr[j] );
            }
        }
        ans = newAns; // ������
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
