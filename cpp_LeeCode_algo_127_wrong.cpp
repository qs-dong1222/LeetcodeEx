#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_set>
#include <set>

using namespace std;
void DFS(unordered_set<string>& wordlist, string& beginword, string& endword, vector<bool>& bitChange, int& step, set<int>& steps);
int main(){
    unordered_set<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    vector<bool> bitChange(endWord.size(), false);
    int step = 0;
    set<int> steps;

    DFS(wordList,beginWord,endWord,bitChange,step,steps);

    for(auto each:steps){
        cout <<each <<endl;
    }

    return 0;
}



void DFS(unordered_set<string>& wordlist, string& beginword, string& endword, vector<bool>& bitChange, int& step, set<int>& steps){
    if(beginword == endword){
        steps.insert(step);
        return;
    }

    int i;
    char exch, ch;
    for(i=0;i<(int)endword.size();i++){
        if(bitChange[i]){
            continue;
        }
        for(exch='a';exch<='p';exch++){
            if(beginword[i]==exch){
                continue;
            }
            ch = beginword[i];
            beginword[i] = exch;
            if(!wordlist.count(beginword)){
                beginword[i] = ch;
                continue;
            }

            step++;
            bitChange[i] = true;
            if(beginword[i] == endword[i]){
                equ[i] = true;
                continue;
            }
            DFS(wordlist, beginword, endword, bitChange, step, steps);
            bitChange[i] = false;
            step--;
            beginword[i] = ch;
        }
    }

}
