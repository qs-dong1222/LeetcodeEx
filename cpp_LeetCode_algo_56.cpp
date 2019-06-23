#include <iostream>
#include <vector>
#include <set>


using namespace std;
 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> merge(vector<Interval>& intervals);

bool operator<(const Interval& A, const Interval& B);

int main(){
    Interval in1(6, 9);
    Interval in2(-3, 4);
    Interval in3(-3, 5);
    Interval in4(11,15);
    Interval in5(12,17);
    Interval in6(18,19);



    vector<Interval> intervals;
    intervals.push_back(in1);
    intervals.push_back(in2);
    intervals.push_back(in3);
    intervals.push_back(in4);
    intervals.push_back(in5);
    intervals.push_back(in6);


    vector<Interval> ans = merge(intervals);

    for(auto each : ans){
        cout << each.start << " " << each.end << endl;
    }


    return 0;
}







bool operator<(const Interval& A, const Interval& B){
    if(A.start > B.start){
        return false;
    }
    else if(A.start == B.start){
        return (A.end < B.end);
    }
    else{
        return true;
    }
}


vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    if(intervals.empty()) return ans;

    // sort first
    set<Interval> s;
    for(auto each : intervals){
        s.insert(each);
    }

    // tmp is used to fill ans vector
    Interval tmp(s.begin()->start, s.begin()->end);

    for(auto each : s){
        if(each.start > tmp.end){
            ans.push_back(tmp);
            tmp.start = each.start;
            tmp.end = each.end;
        }
        else if(each.end > tmp.end){
            // only need to compare the right bound and update the tmp.end only when new right bound is bigger than tmp's
            tmp.end = each.end;
        }
    }
    ans.push_back(tmp);

    return ans;
}

















//bool operator< (const Interval& A, const Interval& B){
//    if(A.start < B.start) return true;
//    if(A.start == B.start){
//        if(A.end < B.end) return true;
//    }
//    return false;
//}
//
//vector<Interval> merge(vector<Interval>& intervals) {
//    if(intervals.empty()) return vector<Interval>(0);
//    set<Interval> intervalSet;
//    vector<Interval> ans;
//
//    // sort
//    for(auto each : intervals){
//        intervalSet.insert(each);
//    }
//
//    Interval tmp(intervalSet.begin()->start, intervalSet.begin()->end);
//    for(auto curr : intervalSet){
//        cout << curr.start << " " << curr.end << endl;
//        if(tmp.start<=curr.start && curr.start<=tmp.end && curr.end>=tmp.end)
//            tmp.end = curr.end;
//
//        if(curr.start > tmp.end){
//            ans.push_back(tmp);
//            tmp.start = curr.start;
//            tmp.end = curr.end;
//        }
//    }
//    ans.push_back(tmp);
//
//    return ans;
//}
