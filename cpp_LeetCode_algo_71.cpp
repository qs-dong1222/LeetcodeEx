#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

string simplifyPath(string path);

int main(){
    cout << simplifyPath("/abc/...") << endl;
//    cout << simplifyPath("/a/./b/../../c/") << endl;

    return 0;
}






string simplifyPath(string path) {
    string ans;
    if(path.empty()) return ans;

    stack<string> stk;
    stringstream strstream;
    string tmps;

    strstream << path;
    while(getline(strstream, tmps, '/')){
        if(tmps == "" || tmps == "."){
            continue;
        }
        else if(tmps == ".."){
            // ������ifд������, Ŀ���Ǳ����ȡ"../xxx"�е�".."
            // ��� !stk.empty() д��else if����, �ͻ����������else, ����".."������stack
            if(!stk.empty()) stk.pop();
        }
        else{
            stk.push(tmps);
        }
    }

    while(!stk.empty()){
        ans.insert(0, stk.top());
        ans.insert(0, "/");
        stk.pop();
    }

    if(ans.empty()) return "/"; // ����Ƿ�ֹ���� "/" ����ʱ, ans�Ľ���Ǹ�"", ɶҲû��. ������Ӧ�÷��� "/".

    return ans;
}








//string simplifyPath(string path) {
//    string ans = "";
//    if(path.empty()) return ans;
//
//    stack<string> stk;
//    stringstream ss;
//    ss<<path;
//    string tmp;
//    while(getline(ss, tmp, '/')){
//        if(tmp=="" || tmp==".")
//            continue;
//        else if(tmp==".."){
//            if(!stk.empty())
//                stk.pop();
//        }
//        else
//            stk.push(tmp);
//    }
//
//    if(stk.empty()) return "/";
//    while(!stk.empty()){
//        ans.insert(0, stk.top());
//        ans.insert(0, "/");
//        stk.pop();
//    }
//    return ans;
//}
