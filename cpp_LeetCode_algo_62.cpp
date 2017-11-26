#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int FindNbrOfPathAtCoord(int r, int c);
unordered_map<string, int> resMap;
int uniquePaths(int m, int n);

int main(){

    cout << uniquePaths(2,2) << endl;

    return 0;
}



int uniquePaths(int m, int n) {
    return FindNbrOfPathAtCoord(m,n);
}


int FindNbrOfPathAtCoord(int r, int c){
    string key;
    key.push_back(r+'0');
    key.push_back(c+'0');
    if(resMap.count(key)){
        return resMap[key];
    }

    if(r==0 && c==0){
        return 1;
    }

    if(r==0 && c!=0){
        resMap[key] = FindNbrOfPathAtCoord(r, c-1);
        return resMap[key];
    }

    if(r!=0 && c==0){
        resMap[key] = FindNbrOfPathAtCoord(r-1, c);
        return resMap[key];
    }

    resMap[key] = FindNbrOfPathAtCoord(r-1,c) + FindNbrOfPathAtCoord(r,c-1);
    return resMap[key];
}
