#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<vector<int>> matrix =
{
  {1,0,1,0,0,1,0,0,1,0},
  {1,0,1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,1,1,1,0},
  {1,0,0,1,0,0,1,0,1,1},
};








//vector<vector<int>> paddingMat;
unordered_map<int,int> sum;
int SumWRTorigin(int r, int c);
int AreaSum(int r, int c, int w, int h);

int main(){
//    paddingMat = vector<vector<int>>(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
//    for(int r=0;r<(int)matrix.size();r++){
//        for(int c=0;c<(int)matrix[0].size();c++){
//            paddingMat[r+1][c+1] = matrix[r][c];
//        }
//    }

//    vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
//    for(int r=1;r<=(int)matrix.size();r++){
//        for(int c=1;c<=(int)matrix[0].size();c++){
//            dp[r][c] = dp[r][c-1] + dp[r-1][c] - dp[r-1][c-1] + paddingMat[r-1][c-1];
//        }
//    }

    for(int r=0;r<(int)matrix.size();r++){
        for(int c=0;c<(int)matrix[0].size();c++){
            SumWRTorigin(r, c);
        }
    }

    int maxArea = 0;
    int tempArea;
    for(int r=matrix.size()-1;r>=0;r--){
        for(int c=matrix[0].size()-1;c>=0;c--){
            for(int w=c+1;w>=1;w--){
                for(int h=r+1;h>=1;h--){
                    if(w!=h) continue; // only count square area
                    tempArea = AreaSum(r,c,w,h);
                    if( tempArea == w*h ){
                        // this area is a rect with full '1's
                        maxArea = max(tempArea, maxArea);
                    }
//                    cout<<"r="<<r<<",c="<<c<<",w="<<w<<",h="<<h<<endl;
                }
            }
        }
    }

    cout << maxArea << endl;

    return 0;
}


int SumWRTorigin(int r, int c){
    int key = (r*7<<2)+c;
    if(sum.count(key)){
        return sum[key];
    }
    if(r<0 || c<0){
        sum[key] = 0;
        return 0;
    }
    sum[key] = SumWRTorigin(r-1,c) + SumWRTorigin(r,c-1) - SumWRTorigin(r-1,c-1) + matrix[r][c];
    return sum[key];
}


int AreaSum(int r, int c, int w, int h){
    return SumWRTorigin(r,c) - SumWRTorigin(r,c-w) - SumWRTorigin(r-h,c) + SumWRTorigin(r-h,c-w);
}
