#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
#include <deque>

using namespace std;

void foo(string& s, int start, int& cut);
bool IsPalindrome(string& str, int startIdx, int endIdx);
int minCut(string s);

int main(){
    string s = "aab";

    cout << minCut(s) << endl;

    return 0;
}




/*
����DP��һ��˼·��
���������ֿ��ܵ���ʽ:
1.�����ַ�
2.������ͬ���ַ�
3.��ͷ�ַ���ͬ���м�����ַ���Ҳ�ǻ���
�������ǿ�����һ������pli[i][j]����ʾ��s[i]��s[j]�Ļ�����Ч��.
��ô���Ǿ���Ҫn*n=n^2��ѭ�������ѭ�����ԴӺ���s[end]��ʼ��Ҳ���Դ�s[0]��ʼ��
ÿÿ�ߵ�s[i][j=i]����true��s[i][j=i+1]���鿴һ��˫�ַ����.

���⵽����������ҪѰ��mincut. �ַ�����ǰ���󿴵Ļ���pli[i][j]˳����:
pli[0][0] pli[0][1] pli[0][2] ... pli[0][end],   pli[1][1] pli[1][2] ... pli[1][end] ...
�Ӻ���ǰ���Ļ����ơ�

����mincut���ԴӺ���ǰ���ƣ�mincut[i]��ʾs[i:end]�е�mincut����. ��ǰ����Ļ���û�취��֤mincut�ĸ��¡�
���pli[i][j]����Ч���ģ���ô�ڸ���mincut[j]���ɡ�

if(isPli[i][j]){
    if(j==(int)s.size()-1)
        mincut[i] = 0;
    else
        mincut[i] = min(mincut[i], mincut[j+1]+1);
}
˵����j=end��ʱ������Ӧ����û��cut�ġ�
�����¹������п�����ʱ����ֶ����cut�����min()����Ϊ�˱�֤���mincutһֱ��������С״̬�µĽ�.
*/
int minCut(string s){
    if(s.empty()) return 0;
    bool isPli[s.size()][s.size()] = {false};
    vector<int> mincut(s.size(), INT_MAX);

    for(int i=(int)s.size()-1; i>=0; i--){
        for(int j=i; j<(int)s.size(); j++){
            // set palindrome correctness
            if(i==j)
                isPli[i][j] = true;
            else if(j==i+1)
                isPli[i][j] = s[j]==s[i]? true:false;
            else
                isPli[i][j] = (s[i]==s[j])&&(isPli[i+1][j-1])? true:false;

            // look for mincut[i] for s[i:end]
            if(isPli[i][j]){
                if(j==(int)s.size()-1)
                    mincut[i] = 0;
                else
                    mincut[i] = min(mincut[i], mincut[j+1]+1);
            }
        }
    }

    return mincut[0];
}




bool IsPalindrome(string& str, int startIdx, int endIdx){
    while(startIdx<=endIdx){
        if(str[startIdx] != str[endIdx])
            return false;
        else{
            startIdx++;
            endIdx--;
        }
    }
    return true;
}
