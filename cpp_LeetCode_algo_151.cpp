#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
void reverseWords(string &s);

int main(){
    string s = " ";

    reverseWords(s);

    cout << s << endl;

    return 0;
}



/*
solution No.1
*/
void reverseWords(string &s) {
    stringstream ss(s);
    string ans;
    while(ss >> s){
        ans = s + " " + ans;
    }
    if(ans.empty() || ans[0]==' '){
        s = ans;
        return;
    }
    ans.pop_back();
    s = ans;
}





/*
solution No.2
*/
//void reverseWords(string &s) {
//    if(s.empty()) return;
//
//    while((int)s.size()>0 && s[0]==' ')
//        s.erase(0, 1);
//    while((int)s.size()>0 && s[s.size()-1]==' ')
//        s.erase(s.size()-1, 1);
//
//    int count = 0;
//    int pos = s.size();
//    int insertPos = 0;
//    int size = s.size();
//    while(count < size){
//        pos--;
//        if(s[pos]==' '){
//            while(count<size && s[pos-1]==' '){
//                s.erase(pos, 1);
//                pos--;
//                count++;
//            }
//
//            string sub = s.substr(pos+1);
//            s.erase(pos, s.size()-pos);
//            s.insert(insertPos, sub+" ");
//            insertPos += (sub + " ").size();
//            pos = s.size();
//        }
//        count++;
//    }
//}
