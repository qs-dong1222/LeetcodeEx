#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//int DFS(string& targetS, string& srcS, int tarIdx, int srcIdx, int& step);

unordered_map<string, int> resMap;
void setZeroes(vector<vector<int>>& matrix);

int main(){

    vector<vector<int>> mat =
//    {
//        {0,1,1,1,1,1,1,1},
//        {1,1,1,1,1,1,1,1},
//        {1,1,0,1,1,1,1,1},
//        {1,1,1,1,1,1,1,1},
//        {1,1,1,1,1,0,1,1},
//        {1,1,1,1,1,1,1,0}
//    };
    {
        {1,1,1,1},
        {1,0,1,1},
        {1,1,1,0},
        {1,1,1,1}
    };

    setZeroes(mat);

    for(auto eachRow : mat){
        for(auto each : eachRow){
            cout << each << " ";
        }
        cout << endl;
    }

    return 0;
}













// ��x������ʱ�Ľⷨ:
// ˼·��Ϊ��, ����ʱ, Ҫ���������һ��λ�����ظ������������
// ���� (1,3)��(1,5) ��������, ���Ƕ���� 1st ��һ�н�������, ��ô���Ǿͻ����ظ�����, ��ʵ��������ֻ��һ�β���������
// ����ķ������� �ȴ�ȫ�ֽǶ���ȥ��¼ÿ�� ��,�� �Ƿ���Ҫ����.
// �����ȫ��һ������һ���������.
void setZeroes(vector<vector<int>>& matrix) {
    vector<bool> rowToBeZero(matrix.size(), false);
    vector<bool> colToBeZero(matrix[0].size(), false);

    for(int r=0; r<(int)matrix.size(); r++){
        for(int c=0; c<(int)matrix[0].size(); c++){
            if(matrix[r][c]==0){
                rowToBeZero[r] = true;
                colToBeZero[c] = true;
            }
        }
    }


    for(int r=0; r<(int)rowToBeZero.size(); r++){
        if(rowToBeZero[r]){
            for(int c=0; c<(int)matrix[0].size(); c++){
                matrix[r][c] = 0;
            }
        }
    }


    for(int c=0; c<(int)colToBeZero.size(); c++){
        if(colToBeZero[c]){
            for(int r=0; r<(int)matrix.size(); r++){
                matrix[r][c] = 0;
            }
        }
    }

}



//void setZeroes(vector<vector<int>>& matrix) {
//    int rowSize = matrix.size();
//    int colSize = matrix[0].size();
//
//    int r,c;
//    bool firstColIsZero = false;
//    bool firstRowIsZero = false;
//
//    for(c=0;c<colSize;c++)
//        if(matrix[0][c]==0)
//            firstRowIsZero = true;
//
//    for(r=0;r<rowSize;r++){
//        if(matrix[r][0]==0)
//            firstColIsZero = true;
//        for(c=0;c<colSize;c++){
//            if(matrix[r][c]==0){
//                matrix[r][0] = 0;
//                matrix[0][c] = 0;
//            }
//        }
//    }
//
//    for(c=1;c<colSize;c++){
//        if(matrix[0][c] == 0){
//            for(r=1;r<rowSize;r++)
//                matrix[r][c] = 0;
//        }
//    }
//
//    for(r=1;r<rowSize;r++){
//        if(matrix[r][0] == 0){
//            for(c=1;c<colSize;c++)
//                matrix[r][c] = 0;
//        }
//    }
//
//    if(firstColIsZero){
//        for(r=0;r<rowSize;r++)
//            matrix[r][0] = 0;
//    }
//    if(firstRowIsZero){
//        for(c=0;c<colSize;c++)
//            matrix[0][c] = 0;
//    }
//}

