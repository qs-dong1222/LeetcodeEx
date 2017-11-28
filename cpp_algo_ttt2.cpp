#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int solution(string &S, int K);

int main(){
    string s = "SMS kkk me   ssag are     really    short";

    cout << solution(s, 10) << endl;

    return 0;
}


int solution(string &S, int K){
    int startIdx = 0;
    int endIdx = 0;
    int ans = 0;

    int currLen;
    for(int i=0; i<S.size(); i++){
        if(S[i]==' '){
            currLen = i-1 - startIdx + 1;
            if(currLen < K){
                endIdx = i;
            }
            else if(currLen == K){
                // length == K
                ans++;
                startIdx = i+1;
            }
        }

        else{
            currLen = i - startIdx +1;
            if(currLen < K){
                continue;
            }
            else if(currLen > K){
                ans++;
                startIdx = endIdx+1;
            }
        }
    }

    if(S.size()-1 - startIdx + 1 > K){
        return -1;
    }

    ans++;
    return ans;
}












int solution(int n) {
    int d[30];
    int l = 0;
    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }
    for (int p = 1; p < 1 + l; ++p) {
        bool ok = true;
        for (int i = 0; i < l - p; ++i) {
            if (d[i] != d[i + p]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return p;
        }
    }
    return -1;
}
