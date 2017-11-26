#include <iostream>
#include <vector>

using namespace std;
string minWindow(string s, string t);

int main(){

    cout << minWindow("DDADABC","ABC") << endl;
    return 0;
}




/*
����˼·̫���룺
���ӣ�s="ABBBAKKKC", t="ABC"
˼·����һ��end������ȥ̽·���ڵ�һ����ȫ����Ҫ���λ��ͣ������Ҳ����s���C����
���Ҳ�����;ɨ��ķ�ʽÿ�ζ�����һ�ε�ǰ�ַ��Ĵ�ƥ���������Ӧ���ֵ��ַ���ƥ��
�����趨Ϊ1����ôɨ��Cʱ�������켣Ӧ��Ϊ: 0 0 -1 -2 -1 -1 -1 -1 0
������һ��Aʱ�����ǰ�����1ɨ��0��ͬ�������ڸ���B����������Bʱ�����ǰ�B�Ĵ�ƥ�����
��1ɨ����-2���ڶ���Aʱ��A�Ĵ�ƥ������Ѿ�ɨ����-1.
���Կ�������endѰ�ҵ���һ������λ��ʱ��ǰ��һ����ƥ��ɹ��ġ�ֻ��˵�������ƥ��㲻֪�������
�������ظ�ƥ�䡣���ǵ�Ŀ�ľ���ȥ�������ƥ��㡣
������������ƥ�����ǵ�����B����ô������begin����ȥ׷end������������;��ȫ�ķ�ʽ��ÿ��һ��
�ط���+1����ô��һ��B��-2����-1���ڶ���B��-1����0��������B�ĳ�ʼ��������0�ˣ���ʱ�����Ǿ��ҵ���
���ƥ��㡣�ڶ���A�ڵ�����B֮�󣬻���֮��̽�⵽��ȫ�����Ե�һ��̽�ⲹȫ��0�ĵ�϶��� ���Ե�ǰend
Ϊ��ֹ�������ƥ��㡣�ڶ���A֮��̽�⵽��ȫΪ0��Ҳ�������Ե�ǰendΪ��ֹ�������ƥ��㡣
*/
string minWindow(string s, string t) {
    vector<int> charCnt(128, 0);
    for(auto each:t)
        charCnt[each]++;

    int begin=0, end=0, head=0;
    int len = INT_MAX;
    int count = t.size();
    while(end<s.size()){
        if(charCnt[s[end]] > 0)
            count--;
        charCnt[s[end]]--;
        end++;

        while(count == 0) {
            if(end-begin<len)
                len = end-(head=begin);
            if(charCnt[s[begin]] == 0)
                count++;
            charCnt[s[begin]]++;
            begin++;
        }
    }

    return len==INT_MAX? "":s.substr(head, len);
}




vector.erase




//string minWindow(string s, string t) {
//    int map[128] = {0};
//    for(auto c: t) map[c]++;
//    int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
//    while(end<s.size()){
//        if(map[s[end]]>0) {
//            counter--; //in t
//        }
//        map[s[end]]--;
//        end++;
//
//        while(counter==0){ //valid
//            if(end-begin<d)  d=end-(head=begin);
//            if(map[s[begin]]==0){
//                counter++;  //make it invalid
//            }
//            map[s[begin]]++;
//            begin++;
//        }
//    }
//    return d==INT_MAX? "":s.substr(head, d);
//}
