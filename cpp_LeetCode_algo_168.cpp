#include <iostream>
#include <vector>
#include <string>

using namespace std;
string convertToTitle(int n);

int main(){

    cout << convertToTitle(1999) << endl;

//    cout << 77 / 26 << endl;

    return 0;
}


string convertToTitle(int n) {
    string ans;
    if(n==0) return ans;

    while(n>0){
        int charOffset = (n-1) % 26;
        ans.insert(0,1,'A'+charOffset);
        n = (n-1) / 26;
    }

    return ans;
}
