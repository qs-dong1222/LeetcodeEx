#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, int> resMap;
unordered_map<int, int> resMap2;
int AreaWRTtopLeft(vector<vector<char>>& matrix, int r, int c);
int AreaDim(vector<vector<char>>& matrix, int Tr, int Tc, int dimW, int dimH);
int maximalRectangle(vector<vector<char>>& matrix);

int main(){

    vector<vector<char>> matrix=
    {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}


int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;

    int ans = INT_MIN;
    for(int r=0;r<matrix.size();r++){
        for(int c=0;c<matrix[0].size();c++){
            for(int dimW=1;dimW<=matrix[0].size()-c;dimW++){
                for(int dimH=1;dimH<=matrix.size()-r;dimH++){
//                    if(dimH==dimW) // square rect
                    ans = max(ans, AreaDim(matrix,r,c,dimW,dimH));
                }
            }
        }
    }

    return ans;
}



int AreaDim(vector<vector<char>>& matrix, int Tr, int Tc, int dimW, int dimH){
    int W = (Tc+dimW-1)>=matrix[0].size()? matrix[0].size()-Tc : dimW;
    int H = (Tr+dimH-1)>=matrix.size()? matrix.size()-Tr : dimH;

    int key = (Tr*7<<3+Tc)+(W*5<<1+H);

    if(Tr==0 && Tc==0){
        resMap2[key] = AreaWRTtopLeft(matrix, Tr+H-1, Tc+W-1);
    }
    else if(Tr==0 && Tc!=0){
        resMap2[key] = AreaWRTtopLeft(matrix, Tr+H-1,Tc+W-1) - AreaWRTtopLeft(matrix, Tr+H-1, Tc-1);
    }
    else if(Tc==0 && Tr!=0){
        resMap2[key] = AreaWRTtopLeft(matrix, Tr+H-1,Tc+W-1) - AreaWRTtopLeft(matrix, Tr-1, Tc+W-1);
    }
    else{
        resMap2[key] = AreaWRTtopLeft(matrix, Tr+H-1,Tc+W-1)
                    - AreaWRTtopLeft(matrix, Tr-1, Tc+W-1)
                    - AreaWRTtopLeft(matrix, Tr+H-1, Tc-1)
                    + AreaWRTtopLeft(matrix, Tr-1, Tc-1);
    }

    resMap2[key] = resMap2[key]==W*H? resMap2[key] : 0;
    return resMap2[key];
}



int AreaWRTtopLeft(vector<vector<char>>& matrix, int r, int c){
    int key = (r*7<<3) + c;
    if(resMap.count(key))
        return resMap[key];

    if(r==0 && c==0){
        resMap[key] = matrix[r][c]-'0';
        return resMap[key];
    }
    if(r==0 && c!=0){
        resMap[key] = AreaWRTtopLeft(matrix, r, c-1) + (matrix[r][c]-'0');
        return resMap[key];
    }
    if(c==0 && r!=0){
        resMap[key] = AreaWRTtopLeft(matrix, r-1, c) + (matrix[r][c]-'0');
        return resMap[key];
    }

    resMap[key] = AreaWRTtopLeft(matrix, r,c-1) + AreaWRTtopLeft(matrix, r-1,c) - AreaWRTtopLeft(matrix, r-1,c-1) + (matrix[r][c]-'0');
    return resMap[key];
}
