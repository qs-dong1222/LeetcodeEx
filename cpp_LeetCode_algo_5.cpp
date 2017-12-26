#include <iostream>
#include <vector>

using namespace std;
bool IsPalindrome(string& s, int lidx, int ridx);
string longestPalindrome(string s);

int main(){
    string s = "aaaa";

    cout << longestPalindrome(s) << endl;

    return 0;
}


/*
solution 1 : brute force
*/
//string longestPalindrome(string s) {
//    int lidx, ridx;
//    int len;
//    for(len=s.size(); len>0; len--){
//        for(lidx=0, ridx=lidx+len-1; ridx<s.size(); lidx++,ridx++) {
//            if(IsPalindrome(s, lidx, ridx)){
//                return s.substr(lidx,len);
//            }
//        }
//    }
//
//    return "";
//}
//
//
//bool IsPalindrome(string& s, int lidx, int ridx){
//    while(lidx < ridx){
//        if(s[lidx++]!=s[ridx--]) return false;
//    }
//    return true;
//}


/*
solution 2 : dynamic programming
*/
//string longestPalindrome(string s){
//    if(s.empty()) return s;
//    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//
//    int maxLen = 1;
//    int lidx = 0;
//    for(int i=(int)s.size()-1;i>=0;i--){
//        for(int j=i;j<(int)s.size();j++){
//            if(j==i){
//                dp[i][j] = true;
//            }
//            else if(j==i+1 && s[j]==s[i]){ // two chars
//                dp[i][j] = true;
//            }
//            else if(j-i+1>2){ // more than 2 chars
//                if(dp[i+1][j-1] && s[i]==s[j]){
//                    dp[i][j] = true;
//                }
//            }
//
//            if(dp[i][j] && j-i+1>maxLen){
//                maxLen = j-i+1;
//                lidx = i;
//            }
//        }
//    }
//
//    return s.substr(lidx, maxLen);
//}



/*
solution 3 : 以各个回文中心往外扩展
*/
string longestPalindrome(string s) {
    int n = s.size(), len = 0, start = 0;
    for(int i = 0; i < n; i++){
        int left = i, right = i;
        while(right < n && s[right+1] == s[right]) right++;
        i = right; // 关键就是这一行, 直接跳过单字符循环的子串
        while(left > 0 && right < n-1 && s[left-1] == s[right+1]){
            left--;
            right++;
        }

        if(len < right-left+1){
            len = right - left + 1;
            start = left;
        }
    }
    return s.substr(start, len);
}






