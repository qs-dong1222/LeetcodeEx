#include <iostream>
#include <vector>

using namespace std;
string minWindow(string s, string t);

int main(){

    cout << minWindow("DDADABC","ABC") << endl;
    return 0;
}




/*
这种思路太难想：
例子：s="ABBBAKKKC", t="ABC"
思路是用一个end索引先去探路，在第一个找全符合要求的位置停下来，也就是s里的C处。
并且采用沿途扫光的方式每次都减少一次当前字符的待匹配次数。将应出现的字符待匹配
次数设定为1，那么扫到C时，次数轨迹应该为: 0 0 -1 -2 -1 -1 -1 -1 0
遇到第一个A时，我们把他从1扫到0，同理适用于各个B，到第三个B时，我们把B的待匹配次数
从1扫到了-2，第二个A时，A的待匹配次数已经扫到了-1.
可以看到，当end寻找到第一个合适位置时，前面一定有匹配成功的。只是说，最近的匹配点不知道在哪里，
而且有重复匹配。我们的目的就是去找最近的匹配点。
这里很明显最近匹配点就是第三个B，那么我们用begin索引去追end索引，采用沿途补全的方式，每到一个
地方就+1，那么第一个B从-2补到-1，第二个B从-1补到0，第三个B的初始次数就是0了，这时候我们就找到了
最近匹配点。第二个A在第三个B之后，会于之后探测到补全。所以第一个探测补全到0的点肯定是 “以当前end
为截止”的最近匹配点。第二个A之后探测到补全为0，也不会是以当前end为截止”的最近匹配点。
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
