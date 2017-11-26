#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

unordered_map<int,int> resMap;

bool isInterleave(string s1, string s2, string s3);
bool DFS(const string& s1, int idx1, const string& s2, int idx2, const string& s3, int idx3);
bool F(const string& s1, int i, const string& s3, int k, const string& s2);

int main(){
//    cout << isInterleave("ababab","acacac","aabcaacbaabc") << endl;

    cout << isInterleave(
    "abbbbbbcabbacaacccababaabcccabcacbcaabbbacccaaaaaababbbacbb",
    "ccaacabbacaccacababbbbabbcacccacccccaabaababacbbacabbbbabc",
    "cacbabbacbbbabcbaacbbaccacaacaacccabababbbababcccbabcabbaccabcccacccaabbcbcaccccaaaaabaaaaababbbbacbbabacbbacabbbbabc"
    ) << endl;

    return 0;
}


/*
DP solution: 和DFS类似的思路，利用记忆递归加速
F(const string& s1, int i, const string& s3, int k, const string& s2):
返回 当s3抽取前k个字符, 且s1抽取前i个字符时(s2的抽取字符个数不用管，必为k-i个)，interleaving的匹配情况
*/
bool isInterleave(string s1, string s2, string s3){
    if(s3.size() != s1.size()+s2.size())
        return false;

    return F(s1, s1.size(), s3, s3.size(), s2);
}

bool F(const string& s1, int i, const string& s3, int k, const string& s2){
    // 这个key没设计好，结果有时候还尼玛不好使，(i*7<<5)+k 就不行, (i*13<<5)+k就好使了
    int key = (i*13<<5) + k;
    if(resMap.count(key))
        return resMap[key];

    if(i==0){
        // s3的前k个字符全是s2提供的
        resMap[key] = s3.substr(0,k) == s2.substr(0,k);
        return resMap[key];
    }

    if(i==k){
        // s3的前k个字符全是s1提供的
        resMap[key] = s3.substr(0,k) == s1.substr(0,k);
        return resMap[key];
    }
                   // s3的下一个字符由s1的下一个字符进行匹配       // s3的下一个字符由s2的下一个字符进行匹配
    resMap[key] = (F(s1, i-1, s3, k-1, s2)&&(s3[k-1]==s1[i-1])) || (F(s1, i, s3, k-1, s2)&&(s3[k-1]==s2[k-1-i]));
    return resMap[key];
}








/*
DFS solution: time limit exceeded
*/
//bool isInterleave(string s1, string s2, string s3){
//    if(s3.size() != s1.size()+s2.size())
//        return false;
//
//    return DFS(s1, 0, s2, 0, s3, 0);
//}
//
//bool DFS(const string& s1, int idx1, const string& s2, int idx2, const string& s3, int idx3){
//    if(idx3 >= s3.size())
//        return true;
//
//    if(s3[idx3]==s1[idx1] && s3[idx3]!=s2[idx2]){
//        if( DFS(s1,idx1+1,s2,idx2,s3,idx3+1) ){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//
//    else if(s3[idx3]==s2[idx2] && s3[idx3]!=s1[idx1]){
//        if( DFS(s1,idx1,s2,idx2+1,s3,idx3+1) ){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//    else if(s3[idx3]==s1[idx1] && s3[idx3]==s2[idx2]){
//        if( DFS(s1,idx1+1,s2,idx2,s3,idx3+1) ){
//            return true;
//        }
//        else if( DFS(s1,idx1,s2,idx2+1,s3,idx3+1) ){
//            return true;
//        }
//        else{
//            return false;
//        }
//    }
//
//    return false;
//}
