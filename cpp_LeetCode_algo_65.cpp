#include <iostream>
#include <vector>

using namespace std;
bool isNumber(string s);

int main(){
    string s = ".e3";
    cout << isNumber(s) << endl;

    return 0;
}


/*
some special cases of non-numeric in this problem are not solved
*/
bool isNumber(string s){
    int lidx=0;
    int ridx=s.size()-1;
    while(s[lidx]==' ')lidx++;
    while(s[ridx]==' ')ridx--;

    if(s.substr(lidx, ridx-lidx+1).empty())
        return false;
    if(s.substr(lidx, ridx-lidx+1).size()==1 && (s[lidx]=='.' || s[lidx]=='e'))
        return false;

    bool foundDot = false;
    bool foundExp = false;
    for(int i=lidx; i<=ridx; i++){
        if( !(s[i]>= '0' && s[i]<='9') ){
            // if not a number
            if(s[i]=='.'){
                if(!foundDot && i<ridx && ((s[i+1]>= '0' && s[i+1]<='9') || s[i+1]=='E' || s[i+1]=='e') )
                    foundDot = true;
                else if(!foundDot && i==ridx && (s[i-1]>= '0' && s[i-1]<='9')){
                    return true;
                }
                else
                    return false;
            }
            else if(s[i]=='e' || s[i]=='E'){
                if(!foundExp && i>lidx && i<ridx &&(s[i+1]>= '0' && s[i+1]<='9') && s[i-1]!='+')
                    foundExp = true;
                else
                    return false;
            }
            else if(s[i]=='-'){
                if( !(i==lidx || (i>lidx&&(s[i-1]=='e'||s[i-1]=='E')))  )
                    return false;
            }
            else if( s[i]=='+' && i==lidx ){
                continue;
            }
            else{
                return false;
            }
        }
    }

    return true;
}
