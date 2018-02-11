#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int FindNbrOfPathAtCoord(int r, int c);
unordered_map<int, int> resMap;
int uniquePaths(int m, int n);
int nPathAtCoord(int r, int c);


int main(){

    cout << uniquePaths(2,2) << endl;

    return 0;
}






int uniquePaths(int m, int n) {
    if(m<0 || n<0) return 0;

    return nPathAtCoord(m-1, n-1);
}


int nPathAtCoord(int r, int c){
    int key = (r*13<<3) + c;
    if(resMap.count(key)){
        return resMap[key];
    }

    if(r==0 && c==0){
        return 1;
    }
    else if(r==0 && c!=0){
        resMap[key] = nPathAtCoord(r, c-1);
    }
    else if(r!=0 && c==0){
        resMap[key] = nPathAtCoord(r-1, c);
    }
    else{
        resMap[key] = nPathAtCoord(r-1, c) + nPathAtCoord(r, c-1);
    }
    return resMap[key];
}









//int uniquePaths(int m, int n) {
//    return FindNbrOfPathAtCoord(m,n);
//}
//
//
//int FindNbrOfPathAtCoord(int r, int c){
//    string key;
//    key.push_back(r+'0');
//    key.push_back(c+'0');
//    if(resMap.count(key)){
//        return resMap[key];
//    }
//
//    if(r==0 && c==0){
//        return 1;
//    }
//
//    if(r==0 && c!=0){
//        resMap[key] = FindNbrOfPathAtCoord(r, c-1);
//        return resMap[key];
//    }
//
//    if(r!=0 && c==0){
//        resMap[key] = FindNbrOfPathAtCoord(r-1, c);
//        return resMap[key];
//    }
//
//    resMap[key] = FindNbrOfPathAtCoord(r-1,c) + FindNbrOfPathAtCoord(r,c-1);
//    return resMap[key];
//}
