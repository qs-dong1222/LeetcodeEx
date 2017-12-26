#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
string convert(string s, int rows);

int main(){

    string s = "AB";

    cout << convert(s, 4) << endl;

    return 0;
}

string convert(string s, int rows) {
    string ans;
    if(s.empty()) return ans;
    if(rows==1) return s;

    vector<string> str(rows, "");

    int rowidx = 0;
    int step = 1;
    for(int i=0;i<s.size();i++){
        str[rowidx].push_back(s[i]);

        if(rowidx==0){
            step = 1;
        }
        if(rowidx==rows-1){
            step = -1;
        }

        rowidx += step;
    }

    for(auto eachS : str){
        ans += eachS;
    }
    return ans;
}


