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

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);

int main(){
    vector<Interval> intervals = { Interval(1,2), Interval(3,5), Interval(6,7), Interval(8,10), Interval(12,16) };
    Interval newInterval(4,9);
    vector<Interval> ans = insert(intervals, newInterval);

    for(auto each : ans)
        cout << each.start << " " << each.end << endl;

    return 0;
}



vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> ans;
    if(intervals.empty()) return newInterval;

    Interval tmp;
    for(int i=0; i<intervals.size(); i++){
        if(newInterval.start > intervals[i].end){
            ans.push_back(intervals[i]);
            continue;
        }

        if(newInterval.start <= intervals[i].start){
            tmp.start = newInterval.start;
        }
        else if(newInterval.start>intervals[i].start && newInterval.start<=intervals[i].end){
            tmp.start = intervals[i].start;
        }
        for(int j=i; j<intervals.size(); j++){
            if(newInterval.end < intervals[j].start){
                tmp.end = newInterval.end;
                ans.push_back(tmp);
                ans.insert(ans.end(), intervals.begin()+j, intervals.end());
                return ans;
            }
            if(newInterval.end>=intervals[j].start && newInterval.end<=intervals[j].end){
                tmp.end = intervals[j].end;
                ans.push_back(tmp);
                ans.insert(ans.end(), intervals.begin()+j+1, intervals.end());
                return ans;
            }
        }
        tmp.end = newInterval.end;
        ans.push_back(tmp);
        return ans;
    }

    ans.push_back(newInterval);
    return ans;
}
