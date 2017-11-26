#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct STR_POS{
    string str;
    string posrecord;
};

int numDistinct(string s, string t);
string recoverStr(string& s, vector<bool>& pos);
void DFS(string& s, string& t, int& ans, vector<bool>& pos, unordered_set<vector<bool>>& visited);
bool isS1hasS2(string& s1, string& s2);

int main(){

    string s = "ccc";
    string t = "c";

    cout << numDistinct(s, t) << endl;

//    vector<bool> pos = {false, false, true, false, true};
//    string s = "12345";
//    cout << recoverStr(s,pos) << endl;

    return 0;
}



/*
ÿÿ���������������������������dp�ⷨ�����е��޴����֣��������ģ��Լ�˼ά���ޣ�ֻ�д���ɽ֮��ϰ�ù�ʯ֮��.
�ⷨ˼·��
������һ���ַ��� s: ...a...a...b..b...c..c.. , '.'��ʾ���������ַ�
����һƥ���ַ��� t: abc

�������һ�����ֶ�������ϵĻ���Ҫ�����abc�����൱����C21ȡa,C21ȡb,C21ȡc���ܹ���8�����
���仰˵�����ǿ�����ȥ��a����ô��a��ѡ���ϣ���һ��aֻ��C11һ��ѡ�񣬶��ڶ���a����C21����ѡ��
��ȥ��b������b����a���棬����b֮ǰ���û����a���Ͳ��ÿ����ˣ������b֮ǰ������a��˵������Ӧ�ý��
a�ĳ���������ͱ���˵�����е�һ��b��ǰ��������a����ô��һ��b���"ab"���������2�֣����۵ڶ���b��
����֮ǰ�Ѿ�������һ��"ab",ͬʱǰ�滹������a����ô���"ab"���������C21*C21=4��. �Դ����ƣ�ֱ��
���ǰ�tߣ�ꡣ

�������ǿ�����ͳ�Ƶ�һ���ַ�'a':
...a.....a.....b.....b......c.....c.....
00011..11222..222222222.............2222 -> 'a'

ͬ��������ͳ�Ƶڶ����ַ�b����"ab"����'a'��ͳ��:
...a.....a.....b.....b......c.....c.....
00011..11222..22222222222222222222222222 -> 'a'
0000.........0022..22444...............4 -> "ab"
���Կ���b��ͳ��������ߵ��Ǹ������ϱߵ��Ǹ����ĺͣ���ҲӦ��������C21*C21�����

ͬ��ͳ��c,����"ab":
...a.....a.....b.....b......c.....c.....
00011..11222..22222222222222222222222222 -> 'a'
0000.........0022..22444....4.....4....4 -> "ab"
000.......................00444..488...8 -> "abc"

�����⣬��������һ�����Ƶ������̡������Ǿ�Ҫ���Ǳ߽�������
���������Ե�һ��'a'��ͳ����˵�ģ������ڵ������棬����ÿ��dp�Ĳ�������һ���ģ�����dp����Ǹ��������Ǹ�����
��ô���ڵ�һ��'a'�����ǿ϶����и���aȥ�ӵ�����һ�ж�������������Ե�һ��'1',�������ܱ�֤����ȷ��'a'ͳ�ơ�
ͬʱ������dp��Ҫ������Ǹ�������ô���ڵ�һ�У����ǿ϶�ҲҪ��ʼ��һ���߽硣����˵���ǵ�һ���ַ�����'a'��
��ô������û��ߵĶ����ܼӣ������������a��ͳ�ƽ��Ӧ����1����ô���Ǿ͵�����߼�һ�г�ʼ��Ϊ0��padding��
����������ȷ��ʼ���㡣
��Ҳ���ϵ�����dp�Ľṹ��dp����ӦΪ��ĸ���+1����ά�Ļ�����(row+1)*(col+1).

��ô�ع�ͷ�������ǿ������dp[i][j]������������ʲô:
����һ��������������'a'ͳ�Ƶĵ�һ��a���ԣ�dp[i][j]����˼���ǣ���s[0:j-1]��delete��substring t[0:i-1]
���ܵĳ��ִ�����
��ô���Ǿ��뵽�߽������ϵ���������dp[0][2]������s[0:2-1]=s[0:1]��delete��substring t[0:0-1]=t[0:-1]���ܵĳ��ִ�����
t[0:-1]��ʵ���ǿ��ַ��������Ե�һ�б߽��������� tΪ��ʱ��s[0:j-1]�г���t�ĳ��ֿ��ܣ��Ǿ�һ�ֿ��ܣ�����
s[0:j-1]���ַ�ȫɾ�ˡ����Ե�һ�ű߽�����ȫ��1.
�����ڵ�һ�б߽��������ԣ�����dp[3][0]����ʾ s[0:0-1]=s[0:-11]��delete��substring t[0:3-1]=t[0:2]���ܵĳ��ִ�����
��s�ǿ��ַ������Ǹ��������ܰ���t�����Ե�һ�б߽�����ȫ��0��


�ݹ�ȫƪ������dp�������ٶ�Ӧ�÷ǳ��졣����̫���룬�»��������ַ�����ɾ�����������⣬���������Ŵ�һ�����ַ��������Կ���
*/
int numDistinct(string& s, string& t) {
    int n = s.length();
    int m = t.length();

    int dp[n+1][m+1];

    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for (int j = 1; j < m+1; j++) {
        dp[0][j] = 0;
    }

    for (int j = 1; j < m+1; j++) {
        for (int i = 1; i < n+1; i++) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1] == t[j-1]) {
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];
}






/*
DFS solution: time limit exceeded
*/
//int numDistinct(string s, string t) {
//    int ans = 0;
//    vector<bool> pos(s.size(), true);
//    unordered_set<vector<bool>> visited;
//
//    DFS(s, t, ans, pos, visited);
//    return ans;
//}
//
//void DFS(string& s, string& t, int& ans, vector<bool>& pos, unordered_set<vector<bool>>& visited){
//    string curr = recoverStr(s, pos);
//
//    if(curr.size() < t.size() || !isS1hasS2(curr, t) ){
//        return;
//    }
//
//    if(curr == t){
//        if(!visited.count(pos)){
//            visited.insert(pos);
//            ans++;
//        }
//        return;
//    }
//
//    // curr.size() is still > t.size(), need more delete
//    for(int i=0;i<s.size();i++){
//        if(!pos[i])
//            continue;
//        pos[i] = false;
//        DFS(s, t, ans, pos, visited);
//        pos[i] = true;
//    }
//}
//
//string recoverStr(string& s, vector<bool>& pos){
//    string ans;
//    for(int i=0;i<s.size();i++){
//        if(pos[i])
//            ans.push_back(s[i]);
//    }
//    return ans;
//}
//
//bool isS1hasS2(string& s1, string& s2){
//    vector<int> chars(128, 0);
//
//    for(int i=0;i<s2.size();i++){
//        chars[s2[i]]++;
//    }
//
//    for(int i=0;i<s1.size();i++){
//        chars[s1[i]]--;
//    }
//
//    for(auto each:chars){
//        if(each > 0)
//            return false;
//    }
//
//    return true;
//}


