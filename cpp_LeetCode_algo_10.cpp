#include <iostream>
#include <vector>

using namespace std;
bool isMatch(string str, string pat);

int main(){
    string str = "qaadgc";
    string pat = "q.*d.";

    cout << isMatch(str, pat) << endl;

    return 0;
}


/*
�����Ƚ���:
����subproblem�Ͳ�����, match[i][j] ��ʾ ԭ�ַ���str[0 : i-1]��pat[0 : j-1] ��ƥ�����.
���� i->i-1 �����ֶ�Ӧ��ϵ��˵���϶�����dp��������һ��һ�еı߽�ֵ������߽�ֵ����Ҫ�Լ���ʼ����
�ؼ�˼����:
1. ������ͬ���ַ�����'.', ˵�����ǿ��԰������ǰ��ͬ���ַ���ɾ����������ǰ����ַ�ƥ�����
2. ����'*', '*'���ܶ������ڣ�ǰ�������һ����*�ַ���
3. ����'*', Ҫô���κ�����û�У������������ַ�ǰ��ƥ��������ɡ�Ҫô'*'���ٴ���һ���ַ�
   ��ʱ��ԭ�ַ����еĵ�ǰ�ַ����ƥ�䣬��ɽ���ɾ����pat��'*'���ܴ��ڶ���ظ��ַ������Խ��䱣����
   �ٶ�ɾ�Ĺ���ԭ�ַ������н�һ��ƥ��.
*/
bool isMatch(string str, string pat) {
    // match[i][j] stands for
    // does str[0 : i-1] match pat[0 : j-1] ?
    vector<vector<bool>> match(str.size()+1, vector<bool>(pat.size()+1, false));

    match[0][0] = true; // empty str for sure matches empty pat

    // initialize 0th row, i.e. match[0][j] ->  empty str match pat[0:j-1]?
    for(int j=2;j<=(int)pat.size();j++){
        // pat cannot have any char, so only "*" is available
        if(j==1 && pat[j-1]=='*'){ // pat[0:1-1] = pat[0]
            match[0][j] = true;
        }
        else if(pat[j-1]=='*'){
            match[0][j] = match[0][j-2];
        }
    }

    for(int i=1;i<(int)match.size();i++){
        for(int j=1;j<(int)match[0].size();j++){
            if(pat[j-1]==str[i-1] || pat[j-1]=='.'){
                // str[i-1] matches with pat[j-1], we can remove those 2 chars and see
                // the previous matching condition in rest of chars
                match[i][j] = match[i-1][j-1];
            }
            // pat[j-1] is '*' and has at least 2 chars
            else if(pat[j-1]=='*' && j>1){
//                // if '*' represents 0 forehead chars, we remove forehead char and '*' from pat
//                if(0 forehead chars){
//                    match[i][j] = match[i][j-2];
//                }
//                // '*' represents at least 1 forehead char, so we can remove this char from str,
//                // there still may be repetitive chars, pat remains "foreCh*"
//                else if('*' at least represents 1 char && pat[j-2]==str[i-1]){
//                    match[i][j] = match[i-1][j];
//                }
                if( match[i][j-2] ||
                   ((pat[j-2]==str[i-1] || pat[j-2]=='.') && match[i-1][j])   ){
                    match[i][j] = true;
                }
            }
        }
    }

    return match[str.size()][pat.size()];
}
