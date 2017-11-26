#include <iostream>
#include <vector>

using namespace std;
void MergeSort(vector<int>& v1, vector<int>& v2, vector<int>& ans);

int main(){
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};
    vector<int> ans;
    MergeSort(v1,v2,ans);

    for(auto each:ans){
        cout << each << " ";
    }
    cout << endl;

    int size = ans.size();
    if(size % 2){
        cout << "odd " << (double)ans[size/2] << endl;
    }
    else{
        cout << "even " << (double)(((double)ans[size/2] + (double)ans[size/2-1])/2) << endl;
    }

    return 0;
}


void MergeSort(vector<int>& v1, vector<int>& v2, vector<int>& ans){
    int idx1=0, idx2=0;
    int size1 = v1.size();
    int size2 = v2.size();

    while(idx1!=size1 || idx2!=size2){
        if(v1[idx1] <= v2[idx2]){
            ans.push_back(v1[idx1]);
            idx1++;
        }
        else{
            ans.push_back(v2[idx2]);
            idx2++;
        }
    }

    if(idx1==size1){
        vector<int>::iterator it = v2.begin();
        advance(it, idx2);
        ans.insert(ans.end(), it, v2.end());
    }

    if(idx2==size2){
        vector<int>::iterator it = v1.begin();
        advance(it, idx1);
        ans.insert(ans.end(), it, v1.end());
    }
}
