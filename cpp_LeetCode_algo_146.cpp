#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class LRU{
private:
    int __capacity;
    unordered_map<int, list<int>::iterator> __key_pointer_map;
    list<int> __val_list;

public:
    LRU(){}

    LRU(int capacity){
        __capacity = capacity;
    }

    int Get(int key){
        auto iter_find = __key_pointer_map.find(key);

        // if this key is not in the hash
        if(iter_find == __key_pointer_map.cend()){
            return -1;
        }
        else{
        // if this key is already in the hash
            int ret =  *(iter_find->second);
            __val_list.splice(__val_list.begin(), __val_list, iter_find->second);
            //iter_find->second = __val_list.begin();// update hash
            return ret;
        }
    }

    int Put(int key, int val){
        auto iter_find = __key_pointer_map.find(key);
        // if this key is already in the hash
        if(iter_find != __key_pointer_map.cend()){
            *(iter_find->second) = val;
            __val_list.splice(__val_list.begin(), __val_list, iter_find->second);
            //iter_find->second = __val_list.begin();// update hash
        }
        // if this key is not in the hash
        else{
//            cout<< "hash size = " << __key_pointer_map.size()<<endl;////////
            if((int)__key_pointer_map.size() >= __capacity){
                // no room, delete one key from __key_pointer_map
                for ( auto& eachPair : __key_pointer_map ){
                    if(*eachPair.second == __val_list.back() ){
                        __key_pointer_map.erase(eachPair.first);
                    }
                }
                // no room, delete one node from __val_list
                __val_list.pop_back();

            }
            // insert the node with val in front
            __val_list.insert(__val_list.begin(), val);
            // update hash
            __key_pointer_map[key] = __val_list.begin();

//            cout<< "hash size = " << __key_pointer_map.size()<<endl;////////
//            for(auto &each: __val_list){
//                cout <<"kkk " << each << endl;
//            }
        }
    }

};






int main(){

    LRU lru(2);

    lru.Put(1,5);
    lru.Put(3,7);

    cout<< lru.Get(1) <<endl;
    cout<< lru.Get(3) <<endl;

    lru.Put(6,9);
    cout<< lru.Get(1) <<endl;
    cout<< lru.Get(6) <<endl;
    cout<< lru.Get(3) <<endl;
    return 0;
}

