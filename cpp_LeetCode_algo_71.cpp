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
            // 这必须把if写在里面, 目的是避免读取"../xxx"中的".."
            // 如果 !stk.empty() 写到else if里面, 就会跳到下面的else, 导致".."被存入stack
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

    if(ans.empty()) return "/"; // 这个是防止单独 "/" 出现时, ans的结果是个"", 啥也没有. 但我们应该返回 "/".

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
