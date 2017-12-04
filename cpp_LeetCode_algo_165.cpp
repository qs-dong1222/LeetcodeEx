#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> Split(string& str, const string& delim);
int compareVersion(string version1, string version2);

int main(){
    string s1 = "12.34.5.7.000000000000000000000.000.00000.0.0.0";
    string s2 = "12.34.5.7";

    cout << compareVersion(s1, s2) << endl;

    return 0;
}



int compareVersion(string version1, string version2) {
    vector<string> sp1 = Split(version1, ".");
    vector<string> sp2 = Split(version2, ".");
    int size = sp1.size()<=sp2.size()? sp1.size():sp2.size();

    for(int i=0;i<size;i++){
        int intsp1 = stoi(sp1[i]);
        int intsp2 = stoi(sp2[i]);

        if(intsp1<intsp2){
            return -1;
        }
        else if(intsp1>intsp2){
            return 1;
        }
    }

    if(sp1.size() > sp2.size()){
        return 1;
    }
    else if(sp1.size() < sp2.size()){
        return -1;
    }
    else{
        return 0;
    }
}



vector<string> Split(string& str, const string& delim){
    int end = str.size()-1;
    while(end>=0){
        if(str[end] != '.'){
            end--;
        }
        else{
            if(stoi(str.substr(end+1)) == 0){
                str.erase(end, str.size()-end);
                end = str.size()-1;
            }
            else{
                break;
            }
        }
    }

    vector<string> ans;
    int findIdx = 0;
    int delimPos = str.find(delim, findIdx);
    while(delimPos>0){
        ans.push_back(str.substr(findIdx, delimPos-findIdx));
        findIdx = delimPos+1;
        delimPos = str.find(delim, findIdx);
    }
    if(stoi(str.substr(findIdx)) != 0)
        ans.push_back(str.substr(findIdx));
    return ans;
}
