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
DP solution: ��DFS���Ƶ�˼·�����ü���ݹ����
F(const string& s1, int i, const string& s3, int k, const string& s2):
���� ��s3��ȡǰk���ַ�, ��s1��ȡǰi���ַ�ʱ(s2�ĳ�ȡ�ַ��������ùܣ���Ϊk-i��)��interleaving��ƥ�����
*/
bool isInterleave(string s1, string s2, string s3){
    if(s3.size() != s1.size()+s2.size())
        return false;

    return F(s1, s1.size(), s3, s3.size(), s2);
}

bool F(const string& s1, int i, const string& s3, int k, const string& s2){
    // ���keyû��ƺã������ʱ�����겻��ʹ��(i*7<<5)+k �Ͳ���, (i*13<<5)+k�ͺ�ʹ��
    int key = (i*13<<5) + k;
    if(resMap.count(key))
        return resMap[key];

    if(i==0){
        // s3��ǰk���ַ�ȫ��s2�ṩ��
        resMap[key] = s3.substr(0,k) == s2.substr(0,k);
        return resMap[key];
    }

    if(i==k){
        // s3��ǰk���ַ�ȫ��s1�ṩ��
        resMap[key] = s3.substr(0,k) == s1.substr(0,k);
        return resMap[key];
    }
                   // s3����һ���ַ���s1����һ���ַ�����ƥ��       // s3����һ���ַ���s2����һ���ַ�����ƥ��
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
