#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
int findCircleNum(vector<vector<int>>& M);
void SinkFriends(vector<vector<int>>& M, int r, int c);
void ExpandCircle(const vector<vector<int>>& M, int p1, vector<bool>& visited);
void print(vector<vector<int>>& M);

int main(){

    vector<vector<int>> M =
    {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

//    {
//        {1,0,0,1},
//        {0,1,1,0},
//        {0,1,1,1},
//        {1,0,1,1}
//    };

    cout << findCircleNum(M) << endl;

    return 0;
}









/*
solution 1 : �Ͼ�����Ȧ�е����й�ϵ.

���ַ���ʱ�临�Ӷ��Ըߣ�����ռ�ռ�
*/
//int findCircleNum(vector<vector<int>>& M) {
//    int ans = 0;
//    if(M.empty()) return ans;
//
//    for(int r=0;r<(int)M.size();r++){
//        for(int c=0;c<(int)M[0].size();c++){
//            if(M[r][c] != 0){
//                ans++;
//                SinkFriends(M, r, c);
//            }
//        }
//    }
//
//    return ans;
//}
//
//void SinkFriends(vector<vector<int>>& M, int p1, int p2){
//    // p1������ʶp2
//    M[p1][p2] = 0;
//    // p2Ҳ������ʶp1
//    M[p2][p1] = 0;
//
//    for(int p=0;p<(int)M[0].size();p++){
//        if(M[p2][p] != 0){
//            //����p2�Ѿ���ʶ������˶Ͼ���ϵ
//            SinkFriends(M, p2, p);
//            //�����ʶp2����Ҳ�Ͼ���ϵ
//            M[p][p2] = 0;
//        }
//    }
//}



/*
solution 2 : ÿ������һ��"֮ǰ���޼�¼/֮ǰ��ȫû����"������ʱ������������Ȧ��
�Դ����ƣ�ֱ����û��"֮ǰ���޼�¼/֮ǰ��ȫû����"������Ϊֹ.

���ַ�����m(n)�Ŀռ临�Ӷȣ���ʱ�临�Ӷ��Ե�
*/
int findCircleNum(vector<vector<int>>& M) {
    vector<bool> visited(M.size(), false);
    int ans = 0;
    for(int p1=0; p1<(int)visited.size(); p1++){
        if (!visited[p1]) {
            visited[p1] = true;
            ans++;
            ExpandCircle(M, p1, visited);
        }
    }
    return ans;
}

void ExpandCircle(const vector<vector<int>>& M, int p1, vector<bool>& visited){
    for(int p2=0; p2<(int)visited.size(); p2++){
        if (M[p1][p2] && !visited[p2]) {
            visited[p2] = true;
            ExpandCircle(M, p2, visited);
        }
    }
}











void print(vector<vector<int>>& M){
    for(int r=0;r<(int)M.size();r++){
        for(int c=0;c<(int)M[0].size();c++){
            cout << M[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
