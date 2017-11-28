#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
string solution(string &S);


int main(){
    string s = "555372654";

    cout << solution(s) << endl;

    return 0;
}

string solution(string &S) {
    string digis;
    for(auto each : S){
        if(each<='9' && each>='0'){
            digis.push_back(each);
        }
    }

    if(digis.size() <= 3){
        return digis;
    }

    int righNbr = digis.size() % 3;
    string ans;
    if(righNbr == 1){
        // four digit at the end, -xx-xx
        for(int i=0;i<=digis.size()-7;i+=3){
            ans += digis.substr(i, 3)+"-";
        }
        ans += digis.substr(digis.size()-4, 4);
        //cout <<ans << endl;
        ans.insert((int)ans.size()-2, 1, '-');
    }

    else if(righNbr == 2){
        // four digit at the end, -xx-xx
        for(int i=0;i<=digis.size()-5;i+=3){
            ans += digis.substr(i, 3)+"-";
        }
        ans += digis.substr((int)digis.size()-2, 2);
    }

    else{
        for(int i=0;i<=digis.size()-3;i+=3){
            ans += digis.substr(i, 3)+"-";
        }
        ans.pop_back();
    }

    return ans;
}
