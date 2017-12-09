#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int visibleNumber(TreeNode* root, int pastPathMax);
int solution(TreeNode* root);

int main(){
    TreeNode n1(5);
    TreeNode n2(3);
    TreeNode n3(10);
    TreeNode n4(20);
    TreeNode n5(21);
    TreeNode n6(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;


    int ans = solution(&n1);
    cout << ans << endl;

    return 0;
}


int visibleNumber(TreeNode* root, int pastPathMax){
    if(!root){
        return 0;
    }

    if(root->val < pastPathMax){
        // current node is not visible
        int leftVisNbr = visibleNumber(root->left, pastPathMax);
        int rightVisNbr = visibleNumber(root->right, pastPathMax);
        return (leftVisNbr + rightVisNbr);
    }

    else{
        // current node is visible
        int leftVisNbr = visibleNumber(root->left, root->val);
        int rightVisNbr = visibleNumber(root->right, root->val);
        return (leftVisNbr + rightVisNbr + 1);
    }

}


int solution(TreeNode* root){
    if(!root){
        return 0;
    }

    int ans = visibleNumber(root, root->val);
    return ans;
}










//int solution(vector<int> &A){
//    int idxCnt = 0;
//    int sum = 0;
//    int ans = 0;
//
//    for(int i = 0; i<(int)A.size(); i++){
//        idxCnt += (i+1);
//        sum += A[i];
//        if(idxCnt == sum){
//            ans++;
//        }
//    }
//    return ans;
//}






//int solution(int N){
//    string num = to_string(N);
//    int maxAns = INT_MIN;
//    permu(num, 0, maxAns);
//    return maxAns;
//}
//
//
//void permu(string& num, int begin, int& maxAns){//set<string>& ansSet){
//    if(begin>=(int)num.size()){
//        //ansSet.insert(num);
//        maxAns = max(maxAns, stoi(num));
//        return;
//    }
//
//    for(int i=begin; i<(int)num.size(); i++){
//        swap(num[begin], num[i]);
//        permu(num, begin+1, maxAns);
//        swap(num[begin], num[i]);
//    }
//}








//int solution(int M, vector<int>& A) {
//    int N = A.size();
//    vector<int> count(M + 1, 0);
//    int maxOccurence = 0;
//    int index = 0;
//    for (int i = 0; i < N; i++) {
//        if (count[A[i]] > 0) {
//            int tmp = count[A[i]]+1;
//            if (tmp > maxOccurence) {
//                maxOccurence = tmp;
//                index = i;
//            }
//            count[A[i]] = tmp;
//        } else {
//            count[A[i]] = 1;
//        }
//    }
//    return A[index];
//}
