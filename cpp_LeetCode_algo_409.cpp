#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int longestPalindrome(string s);

int main(){
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    cout << longestPalindrome(s) <<endl;

    return 0;
}


int longestPalindrome(string s){
    vector<int> freq(2*26, 0);
    for(auto each:s){
        if(each>90){
            freq[each-'A'-6]++;
        }
        else{
            freq[each-'A']++;
        }
    }

    int ans=0;
    int plusOne = 0;
    for(auto each:freq){
        ans += (each>>1)<<1;
        plusOne = (each & 1)==1? 1:plusOne;
    }
    ans+=plusOne;
    return ans;
}

