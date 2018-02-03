#include <iostream>
#include <vector>
#include <set>

using namespace std;

//void per(string& str, int begin, set<string>& ans);
//string generateStr(int n);
string getPermutation(int n, int k);
vector<int> fac(int n);
vector<int> genNums(int n);
void helper(string& ans, vector<int>& nums, vector<int>& fac, int k);

int main(){

    cout << getPermutation(4, 12) << endl;

    return 0;
}





vector<int> fac(int n){
    vector<int> ans;
    ans.push_back(1);

    int tmp = 1;
    for(int i=1;i<=n;i++){
        tmp *= i;
        ans.push_back(tmp);
    }
    return ans;
}


vector<int> genNums(int n){
    vector<int> nums(1,1);
    for(int i=2;i<=n;i++){
        nums.push_back(i);
    }
    return nums;
}



void helper(string& ans, vector<int>& nums, vector<int>& fac, int k){
    if(nums.empty()) return;

    int n_subElem = fac[nums.size()-1];
    int pos = k / n_subElem;

    ans.push_back(nums[pos]+'0');
    nums.erase(nums.begin() + pos);
    helper(ans, nums, fac, k - (k / n_subElem) * n_subElem);
}




string getPermutation(int n, int k){
    vector<int> nums = genNums(n);
    vector<int> factorial = fac(n);
    string ans;
    helper(ans, nums, factorial, k-1);

    return ans;
}


















/*
牛逼算法:
这个算法的思路起点是去找规律，从一个例子中找规律.
例子：n=4 --> "1234" , 全排列为
1234    1st
1243    2nd
1324    3rd
1342    4th
1423    5th
1432    6th
-----------
2134    7th
2143    8th
2314    9th
2341    10th
2413    11th
2431    12th
------------
3124    13th
3142    14th
3214    15th
3241    16th
3412    17th
3421    18th
...     ...

我们可以观察到全排列是以各个字符 ‘1’ ‘2’ ‘3’ ‘4’ 分别为起始字符。每个起始字符以6个排列为一组，
即以 3! 个全排列为一组 = 以 (string.size-initChar.size)! = (string.size-1)! 个全排列为一组.
假如说我们求15th。这说明我们已经跳过了前两个组(1st~12th), 即跳过了3!*(15/3!)个全排列. 这个时候
的全排列应该以'3'打头，也就是(‘1’ ‘2’ ‘3’ ‘4’)中的第3个, 即第(15/3!)+1个。此时我们确定了第一个字符.
同理我们可以找到第二个字符，此时剩余待排列字符为 ‘1’ ‘2’ ‘4’, 并在‘3’打头的全排列中搜索, 那么
就应该搜索第(15-12)th = (15-3!*(15/3!))th = 3th全排列. 此时再去寻找打头字符，每个打头字符应该有
2! 个全排列。那么，就跳过了 2!*(3/2!)=2 个全排列, 即打头字符为第(3/2!)+1=2个, 即‘2’. 此时已得到"32".
后续以此类推即可。

这个思路其实很不好想，我们首先要列出所有可能，寻找规律，如果一个规律没找好，就得不出结论。
*/

//string getPermutation(int n, int k) {
//    if(n==0 || k==0) return "";
//    string leftOverInitChar = "123456789";
//    vector<int> factorial = fac(n);
//    string ans;
//
//    int currFac;
//    k--;
//    while(n>=1){
//        currFac = factorial[n-1];
//        ans.push_back( leftOverInitChar[k/currFac] );
//        leftOverInitChar.erase(k/currFac, 1);
//        k = k%currFac;
//        n--;
//    }
//    return ans;
//}
//
//
//vector<int> fac(int n){
//    if(n==0) return vector<int>(1,1);
//
//    vector<int> ans;
//    ans.push_back(1); // 0!
//    int a=1;
//    for(int i=1;i<=n;i++){
//        a *= i;
//        ans.push_back(a);
//    }
//    return ans;
//}
//
//












/*
超时算法，全枚举排列，排序，再数数。
太多无用功
*/
//string getPermutation(int n, int k) {
//    string str = generateStr(n);
//    set<string> ans;
//    per(str, 0, ans);
//    set<string>::iterator it=ans.begin();
//    for(int i=0; i<k-1; i++) advance(it,1);
//    return *it;
//}
//string generateStr(int n){
//    string ans;
//    for(int i=1;i<=n;i++){
//        ans.push_back(i+'0');
//    }
//    return ans;
//}
//void per(string& str, int begin, set<string>& ans){
//    if(begin >= str.size()){
//        ans.insert(str);
//        return;
//    }
//
//    for(int i=begin; i<str.size(); i++){
//        swap(str[begin], str[i]);
//        per(str, begin+1, ans);
//        swap(str[begin], str[i]);
//    }
//}
