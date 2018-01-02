#include <iostream>
#include <vector>

using namespace std;
bool isMatch(string s, string p);

int main(){
    string s =
    "abcljqwmdc";

    string p =
    //"ab*km?dc";
    //"ab*";
    //"abc?*";
    "ab*w??*";


    cout << isMatch(s, p) << endl;


    return 0;
}




/*
solution: �����͵�10����ʵ���񣬶���dp����Ϳ����ˡ�����˵һ��ϸ��˼·��
1. match[i][j]�ı�ʾ����͵�10����һ���ġ�
2. ���� p[j-1]=s[i-1] �� p[j-1]='?' �������������pat��ori�ж�ɾȥ��ǰ��pat[j-1]��ori[i-1]��
   �ٿ�֮ǰ���ַ���ƥ������Ϳ�����, ����match[i-1][j-1]
3. �����ǰpat[j-1]='*'
   1)���'*'ƥ����ַ�, ���ǾͿ�patɾ��'*'���ƥ�����, ����match[i][j-1]
   2)���'*'ƥ������һ���ַ�.
     2.1)'*'ƥ�����ori�к�����ƥ���ַ����е����ַ�, ������ori��pat�и�ɾ���ַ�, ��match[i-1][j-1]����
     2.2)'*'ƥ�����ori�к�����ƥ���ַ����еķ����ַ�, ���Ǿ�ȥ����'*'��ori��ǰһλ����ƥ�����ʲô���, ����match[i-1][j]
   ���������������һ����true, ������ʹ��ƥ�����
*/
bool isMatch(string s, string p) {
    if(p.empty() && s.empty()) return true;

    vector<vector<bool>> match(s.size()+1,vector<bool>(p.size()+1, false));

    match[0][0] = true;
    for(int j=1;j<(int)match[0].size();j++){
        if(p[j-1]=='*'){
            match[0][j] = match[0][j-1];
        }
    }

    for(int i=1;i<(int)match.size();i++){
        for(int j=1;j<(int)match[0].size();j++){
            if(p[j-1]==s[i-1] || p[j-1]=='?'){
                match[i][j] = match[i-1][j-1];
            }
            else if(p[j-1]=='*'){
                match[i][j] = (match[i][j-1] || match[i-1][j-1] || match[i-1][j]);
            }
        }
    }

    return match[match.size()-1][match[0].size()-1];
}
