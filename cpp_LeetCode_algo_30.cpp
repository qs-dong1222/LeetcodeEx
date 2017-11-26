#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void per(vector<string>& words, int n, int d, vector<string>& ans, string& curr, vector<bool>& used);

int main(){
    vector<string> words = {"foo", "abc", "mmm"};
    vector<bool> used(words.size(), false);
    string curr = "";
    vector<string> ans;

    per(words, words.size(), 0, ans, curr, used);

    for(auto each : ans){
        cout << each << endl;
    }

    set<int> resSet;
    vector<int> resTemp;
    for(auto eachSubStr : ans){
        resTemp = KMPsearch(s, eachSubStr);
        if(!resTemp.empty()){
            for(auto each : resTemp){
                resSet.insert(each);
            }
        }
    }

    return 0;
}




void per(vector<string>& words, int n, int d, vector<string>& ans, string& curr, vector<bool>& used){
    if(d==n){
        ans.push_back(curr);
        return;
    }
    string temp;
    for(int i=0; i<(int)words.size(); i++){
        if(used[i]) continue;

        used[i] = true;
        temp = curr;
        curr = curr + words[i];
        per(words, n, d+1, ans, curr, used);
        curr = temp;
        used[i] = false;
    }
}
