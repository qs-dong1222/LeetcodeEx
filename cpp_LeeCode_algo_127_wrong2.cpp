#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void BuildSubgraph(unordered_set<string>& wordList, string beginWord, unordered_map<string, vector<string>>& graph){
    string temp;
    char ch;
    int i;
    for(i=0;i<(int)beginWord.size();i++){
        temp = beginWord;
        for(ch='a';ch<='z';ch++){
            temp[i] = ch;
            if(beginWord == temp){
                continue;
            }
            if(wordList.count(temp)){
                graph[beginWord].push_back(temp);
            }
        }
    }
}





void BFS(unordered_map<string, vector<string>>& graph, string beginWord, string endWord, int& step, set<int>& minSteps, unordered_set<string>& visited){
    if(beginWord == endWord){
        minSteps.insert(step);
        return;
    }

    for(auto word:graph[beginWord]){
        if(visited.count(word)){
            continue;
        }
        visited.insert(word);
        step++;
        BFS(graph, word, endWord, step, minSteps,visited);
        step--;
        visited.erase(word);
    }

}












int main(){
//    unordered_set<string> wordList = {"hot","dot","dog","lot","log","cog","him"};
    unordered_set<string> wordList = {"hot","dog"};
    unordered_map<string, vector<string>> graph;
    string beginWord = "hot";
    string endWord = "dog";

    BuildSubgraph(wordList,beginWord,graph);
    for(auto each:wordList){
        BuildSubgraph(wordList,each,graph);
    }

    int step = 0;
    set<int> minSteps;
    unordered_set<string> visited;
    BFS(graph, beginWord, endWord, step, minSteps, visited);

//    for(auto each: minSteps){
//        cout << each <<endl;
//    }
    cout << *minSteps.begin()+1 <<endl;

    return 0;
}
