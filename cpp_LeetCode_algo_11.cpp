#include <iostream>
#include <vector>

using namespace std;

int main(){

    return 0;
}



int maxArea(vector<int>& height) {
    int maxA = 0;
    int i=0, j=height.size()-1;
    int tmpArea;

    while(i<j){
        maxA = max( (j-i)*min(height[i], height[j]), maxA );
        if(height[j] > height[i]) i++;
        else j--;
    }
    return maxA;
}
