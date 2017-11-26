#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
bool IsValid(unordered_set<string>& wordSet, string& word, unordered_set<string>& visited);
//void findSolution(string& beginWord, string& endWord, unordered_set<string>& wordSet, vector<vector<string>>& ans, vector<string>& curr, unordered_set<string>& visited);
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
void findSolution(string& beginWord, string& endWord, int& minStep,vector<vector<string>>& ans, vector<string>& curr, unordered_map<string, unordered_set<string>>& parentOf);
int BFSbulidTree(string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_map<string, unordered_set<string>>& parentOf);

vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
string beginWord = "hit";
string endWord = "cog";
unordered_map<string, unordered_set<string>> parentOf;
unordered_set<string> wordSet(wordList.begin(), wordList.end());

int main(){

//    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
//    string beginWord = "qa";
//    string endWord = "sq";





    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);

    for(auto eachRow : ans){
        for(auto each :eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

//    for(auto eachWord : wordSet){
//        cout << eachWord << " : ";
//        for(auto eachDad : parentOf[eachWord]){
//            cout << eachDad << " ";
//        }
//        cout << endl;
//    }

    return 0;
}



vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//    unordered_set<string> wordSet(wordList.begin(), wordList.end());
//    unordered_map<string, unordered_set<string>> parentOf;
    int steps = BFSbulidTree(beginWord, endWord, wordSet, parentOf);
    vector<string> curr(1, endWord);
    vector<vector<string>> ans;
    findSolution(beginWord, endWord, steps, ans, curr, parentOf);

    return ans;
}

void findSolution(string& beginWord, string& endWord, int& minStep,vector<vector<string>>& ans, vector<string>& curr, unordered_map<string, unordered_set<string>>& parentOf){
    if(beginWord == endWord && (int)curr.size()<=minStep+1){
        ans.push_back(curr);
        return;
    }
    else if((int)curr.size() > minStep+1){
        return;
    }

    for(auto eachFather : parentOf[endWord]){
        curr.insert(curr.begin(), eachFather);
        findSolution(beginWord, eachFather, minStep, ans, curr, parentOf);
        curr.erase(curr.begin());
    }
}


/*
构建各个子节点的所有有效父节点，有效在这里指的是最短步数到达当前点的有效父节点.
后续层更长数步长的父节点不考虑。
*/
//int BFSbulidTree(string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_map<string, unordered_set<string>>& parentOf){
//    queue<string> q;
//    unordered_set<string> visited;
//    unordered_map<string, int> parentStep;
//
//    int steps = -1;
//    q.push(beginWord);
//    string curr;
//    bool isEnd = false;
//    while(!q.empty() && !isEnd){
//        steps++;
//        for(int i=(int)q.size()-1; i>=0; i--){
//            curr = q.front(); q.pop();
//            visited.insert(curr);
//
//            string currBackup = curr;
//            for(int pos=0; pos<(int)curr.size(); pos++){
//                char backup = curr[pos];
//                for(char ch='a'; ch<='z'; ch++){
//                    curr[pos] = ch;
//                    if(wordSet.count(curr) && !visited.count(curr) && curr !=currBackup){
//                        if(curr == endWord){
//                            isEnd = true;
//                        }
//                        // 孩儿啊，你要是没爹，我就是你爹，你目前爹的步数就应该是我
//                        // 要是孩儿你有爹了，但是你爹的步长大于等于我，那我也算你爹
//                        // 步长肯定是从短的开始一步步变长，最多出现同一步长的那一层有多个爹的情况
//                        // 后续层的步长一定很长，也不用考虑加爹了
//                        if(!parentOf.count(curr) || parentStep[curr] >= steps){
//                            parentStep[curr] = steps;
//                            parentOf[curr].insert(currBackup);
//                            q.push(curr);
//                        }
//
//                    }
//                }
//                curr[pos] = backup;
//            }
//        }
//    }
//
//    return ++steps;
//}






















int BFSbulidTree(string& beginWord, string& endWord, unordered_set<string>& wordSet, unordered_map<string, unordered_set<string>>& parentOf){
    if(!wordSet.count(endWord)){
        return -1;
    }
    unordered_set<string> qforward;
    unordered_set<string> qbackward;
    unordered_set<string> visited;
//    unordered_map<string, int> parentStep;

    int steps = -1;
    qforward.insert(beginWord);
    qbackward.insert(endWord);
    string curr;
    bool isEnd = false;
    bool swaped = false;
    while(!qforward.empty() && !qbackward.empty() && !isEnd){
        steps++;

        if(qforward.size() > qbackward.size()){
            swap(qforward, qbackward);
            swaped = !swaped;
        }

        unordered_set<string> nextq;
        for(auto each : qforward){
            curr = each;
            visited.insert(curr);

            string currBackup = curr;
            for(int pos=0; pos<(int)curr.size(); pos++){
                char backup = curr[pos];
                for(char ch='a'; ch<='z'; ch++){
                    curr[pos] = ch;
                    if(wordSet.count(curr) && !visited.count(curr)){
                        if(qbackward.count(curr)){
                            isEnd = true;
                        }
                        if(!swaped){
                            parentOf[curr].insert(currBackup);
                        }
                        else{
                            parentOf[currBackup].insert(curr);
                        }
                        nextq.insert(curr);
                    }
                }
                curr[pos] = backup;
            }
        }

        swap(qforward, nextq);
    }

    return ++steps;
}
