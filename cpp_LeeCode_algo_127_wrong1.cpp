#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
int BFS(unordered_set<string>& wordList, string& beginWord, string& endWord);

int main(){
    unordered_set<string> wordList = {"hot","cog","dot","dog","lot","log"};
    string beginWord = "hit";
    string endWord = "cog";

    int res = BFS(wordList,beginWord,endWord);

    cout << res <<endl;

    return 0;
}



/*
单向BFS
*/
//int BFS(unordered_set<string>& wordList, string& beginWord, string& endWord){
//    queue<string> wordGoingToVis;
//    unordered_set<string> visited;
//    int len = endWord.size();
//    char exch, ch;
//    int step=0;
//    int i;
//    int qSize;
//
//    string curr;
//    string tmp;
//    wordGoingToVis.push(beginWord);
//    while(!wordGoingToVis.empty()){
//        step++;
//        qSize = wordGoingToVis.size();
//        for(int q=0;q<qSize;q++){
//            curr = wordGoingToVis.front();
//            wordGoingToVis.pop();
//            visited.insert(curr);
//
//            for(i=0;i<len;i++){
//                ch = curr[i];
//
//                for(exch='a';exch<='z';exch++){
//                    curr[i] = exch;
//                    if(wordList.count(curr) && !visited.count(curr)){
//                        if(curr == endWord) return step+1;
//                        wordGoingToVis.push(curr);
//                    }
//                }
//                curr[i] = ch;
//            }
//        }
//    }
//
//    return 0;
//}







/*
双向BFS
*/
int BFS(unordered_set<string>& wordList, string& beginWord, string& endWord){
    int len = endWord.size();
    int step=0;
    unordered_set<string> visited;
    unordered_set<string> q1;
    unordered_set<string> q2;
    unordered_set<string> nextLevelq;
    char ch, exch;

    q1.insert(beginWord);
    q2.insert(endWord);
    while(!q1.empty() && !q2.empty()){
        step++;

        if(q1.size() > q2.size()){
            swap(q1,q2);
        }

        nextLevelq.clear();
        for(auto curr : q1){
//            q1.erase(curr);   // 你妈个蛋 遍历unordered_set的时候不能对其做变动
            visited.insert(curr);
            for(int i=0;i<len;i++){
                ch = curr[i];
                for(exch='a';exch<='z';exch++){
                    curr[i] = exch;
                    if(wordList.count(curr) && !visited.count(curr)){
                        if(q2.count(curr)){
                            return step+1;
                        }
                        nextLevelq.insert(curr);
                    }
                }
                curr[i] = ch;
            }
        }
        swap(nextLevelq,q1);
    }

    return 0;
}
