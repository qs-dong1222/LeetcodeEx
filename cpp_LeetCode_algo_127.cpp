#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

int BFS(unordered_set<string>& wordList, string start, string end);

int main(){
    unordered_set<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";

    cout << BFS(wordList, beginWord, endWord) << endl;

//    for(auto each:steps){
//        cout <<each <<endl;
//    }

    return 0;
}

int BFS(unordered_set<string>& wordList, string start, string end){
    queue<string> going2visit;
    int step=0;
    unordered_set<string> visited;
    vector<bool> bitChange(start.size(), false);

    going2visit.push(start);
    string curr;
    char c;
    while(!going2visit.empty()){
        curr = going2visit.front();
        going2visit.pop();
        visited.insert(curr);
//        cout << "visited: " <<curr <<endl;

        for(int i=0;i<(int)end.size();i++){
            c = curr[i];
            for(char ch='b';ch<='p';ch++){
                if(curr==end){
                    step++;
//                    cout << "step = " <<step << endl;
                    return step;
                }

                curr[i] = ch;
                if(wordList.count(curr) && !visited.count(curr)){
                    going2visit.push(curr);
                    if(!bitChange[i]){
                        step++;
                        bitChange[i] = true;
                    }
                }
            }
            curr[i] = c;
        }

    }

    return 0;
}
