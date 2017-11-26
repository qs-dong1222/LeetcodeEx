#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> restoreIpAddresses(string s);

int main(){
    vector<string> ans = restoreIpAddresses("172162541");

    for(auto each : ans){
        cout << each << endl;
    }

    return 0;
}


vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    string res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                int len = s.size() -i-j-k;
                if(len>=1 && len<=3){
                    int a = stoi(s.substr(0,i));
                    int b = stoi(s.substr(i,j));
                    int c = stoi(s.substr(i+j,k));
                    int d = stoi(s.substr(i+j+k));
                    if(a<=255 && b <=255 && c<=255 && d<=255){
                        res = to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
                        if(res.size()==s.size()+3) ans.push_back(res);
                    }
                }
            }
        }
    }

    return ans;
}
