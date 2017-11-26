#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

void GetNextArray(char* pattern, int* next);
int KMPsearch(char* text, char* pattern);


int main(){
    char* text = "aaabckkababaabcccc";
    char* pattern = "abc";

    KMPsearch(text, pattern);

    return 0;
}



// function to find "next" array
void GetNextArray(char* pattern, int* next){
    int size = strlen(pattern);

    // current char's longest prefix & suffix matched length
    int pfsfLen = 0;
    // next[0] is always 0
    next[0] = 0;
    // suffix matching string starting index
    int i = 1;

    while(i < size){
        if(pattern[pfsfLen] == pattern[i]){
            pfsfLen++;
            next[i] = pfsfLen;
            i++;
        }
        else{
            if(pfsfLen != 0){ // not 0th character case
                pfsfLen = next[pfsfLen-1];
            }
            else{ // 0th character case
                next[i] = 0;
                i++;
            }
        }
    }
}



int KMPsearch(char* text, char* pattern){
    int patLen = strlen(pattern);
    int txtLen = strlen(text);

    int* next = (int *)malloc(sizeof(int) * patLen);

    GetNextArray(pattern, next);

    int txtIdx=0;
    int patIdx=0;

    while(txtIdx<txtLen){
        if(text[txtIdx] == pattern[patIdx]){
            txtIdx++;
            patIdx++;
            if(patIdx == patLen){
                cout << "match @index = " << txtIdx-patLen << endl;
                patIdx = next[patIdx-1];
            }
        }
        else{
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (patIdx != 0)
                patIdx = next[patIdx-1];
            else
                txtIdx++;
        }
    }

    free(next);
}
