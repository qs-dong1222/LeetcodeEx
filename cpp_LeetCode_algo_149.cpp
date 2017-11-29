#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <float.h>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


int maxPoints(vector<Point>& points);
long double GetSlope(Point A, Point B);

int main(){
    vector<Point> points = {Point(0,0), Point(94911151,94911150), Point(94911152,94911151)};
//    {
//        Point(1,1), Point(1,3), Point(2,2), Point(3,0),
//        Point(3,1), Point(3,4), Point(3,5), Point(5,5)
//    };

    cout << maxPoints(points) << endl;

    return 0;
}



/*
use long double slope as a key, there is still a problem. For large distance points,
the precision in double can not be guaranteed.
*/
int maxPoints(vector<Point>& points) {
    if(points.size() < 2) return points.size();

    int ans = 1;

    for(int i=0; i<(int)points.size(); i++){
        unordered_map<long double, unordered_set<Point*>> slopeSet;
        int NbrOverlapPoints = 1;
        int NbrVertical = 0;
        for(int j=i+1; j<(int)points.size(); j++){
            if(points[i].x == points[j].x){
                if(points[i].y == points[j].y){
                    // overlap points
                    NbrOverlapPoints++;
                }
                else{
                    // vertical points
                    NbrVertical++;
                }
            }
            else{
                double currSlope = GetSlope(points[i], points[j]);
                slopeSet[currSlope].insert(&points[j]);
            }
        }

        int sizeMax = 0;
        for(auto it=slopeSet.begin(); it!=slopeSet.end(); it++){
            sizeMax = max( sizeMax, (int)((it->second).size() ));
        }
        int NbrOtherPoints = max(NbrVertical, sizeMax);
        ans = max(NbrOtherPoints + NbrOverlapPoints, ans);
    }

    return ans;
}



long double GetSlope(Point A, Point B){
    long double slope = (long double)(A.y - B.y) / (long double)(A.x - B.x);
    return slope;
}
