#include <iostream>
#include <stdlib.h>
#include <unordered_map>
#include <list>
#include <vector>
#include <cmath>
#include <sstream>
#include <memory>

using namespace std;


class Trie{
private:
    struct TreeNode{
        char ch;
        bool endOfWord;
        unordered_map<char, TreeNode*> subTreeMap;
    };

    TreeNode* proot;
//    shared_ptr<TreeNode> proot;

public:
    Trie(){
        proot = new TreeNode;
//        proot(new TreeNode);
        proot->endOfWord = false;
    }
    ~Trie(){
        delete proot;
    }

    void Insert(string word){
        TreeNode* ptemp = proot;
        for(auto eachChar : word){
            if(ptemp->subTreeMap.find(eachChar) == ptemp->subTreeMap.cend()){
                ptemp->subTreeMap[eachChar] = new TreeNode;
                ptemp->subTreeMap[eachChar]->ch = eachChar;
                ptemp->subTreeMap[eachChar]->endOfWord = false;
                ptemp = ptemp->subTreeMap[eachChar];
            }
            else{
                ptemp = ptemp->subTreeMap[eachChar];
            }
        }
        ptemp->endOfWord = true;
    }


    bool Search(string str){
        TreeNode* ptemp = proot;
        for(auto eachChar: str){
            if(ptemp->subTreeMap.find(eachChar) != ptemp->subTreeMap.cend()){
                ptemp = ptemp->subTreeMap[eachChar];
            }
            else{
                return false;
            }
        }
        if(ptemp->endOfWord == true){
            return true;
        }
        else{
            return false;
        }
    }


    bool StartWith(string str){
        TreeNode* ptemp = proot;
        for(auto eachChar: str){
            if(ptemp->subTreeMap.find(eachChar) != ptemp->subTreeMap.cend()){
                ptemp = ptemp->subTreeMap[eachChar];
            }
            else{
                return false;
            }
        }
        return true;
    }



    void show(string s){
        TreeNode* ptemp = proot;
        for(auto eachChar: s){
            if(ptemp->subTreeMap.find(eachChar) != ptemp->subTreeMap.cend()){
                ptemp = ptemp->subTreeMap[eachChar];
                cout << ptemp->ch <<" is this char an end of a word? "<< ptemp->endOfWord <<endl;
            }
        }
    }

};







int main(){
    Trie tr;
    tr.Insert("nihao");
    tr.Insert("nibuhao");
    tr.Insert("ni");
//    tr.show("nibuhao");

    cout << tr.Search("nim") <<endl;


    return 0;
}


