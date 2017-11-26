#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <cmath>
#include <memory>
#include <set>
#include <ctime>

using namespace std;

class LFU{
private:
    struct __DataNode{
        int key;
        int data;
        int freq;
        clock_t touchTime;
        bool operator<(const __DataNode& a) const{
            if(this->freq < a.freq){
                return true;
            }else{return false;}
            if(this->freq == a.freq){
                if(this->touchTime <= a.touchTime) return true;
                else return false;
            }
        }
    };

    int __capacity;
    unordered_map<int, __DataNode*> keyPmap;
    set<__DataNode> valSet;

public:
    LFU(int capacity){
        __capacity = capacity;
    }

    ~LFU(){
        ;
    }

    void Put(int key, int data){
        // if key is in the map, add freq and update touchtime
        if(keyPmap.find(key) != keyPmap.cend()){
            Visit(keyPmap[key]);
        }
        // if key is not in the map
        else if((int)keyPmap.size()<__capacity){
            // add a new key in keyPmap and add a new node in valSet if it has capacity
            AddNew(key, data);
        }
        else{
            // add a new key in keyPmap and add a new node in valSet if it has capacity
            DeleteFU();
            AddNew(key, data);
        }
    }

    int Get(int key){
        if(keyPmap.find(key) != keyPmap.cend()){
            Visit(keyPmap[key]);
            return keyPmap[key]->data;
        }
        else return -1;
    }

    void Visit(__DataNode* pnode){
        pnode->freq++;
        pnode->touchTime = clock();
        valSet.erase(*pnode);
        valSet.insert(*pnode);
    }

    void AddNew(int key, int data){
        keyPmap[key] = new __DataNode;
        keyPmap[key]->key = key;
        keyPmap[key]->data = data;
        keyPmap[key]->freq = 1;
        keyPmap[key]->touchTime = clock();
        valSet.insert(*keyPmap[key]);
    }

    void DeleteFU(){
        keyPmap.erase( (*valSet.begin()).key );
        valSet.erase(valSet.begin());
    }

    void show(){
        for(auto each:keyPmap){
            cout<<"key= "<<each.second->key
                <<" data= "<<each.second->data
                <<" freq="<<each.second->freq
                <<" touchTime="<<each.second->touchTime<<endl;
        }
    }
};






int main(){
    LFU lfu(3);
    lfu.Put(10, 7);
    lfu.Put(6, 9);
    lfu.Put(15, 18);
    lfu.show();
    cout<<endl;

    lfu.Put(16, 20);
    lfu.show();
    cout<<endl;

    cout << lfu.Get(15) <<endl;
    lfu.show();

    return 0;
}
