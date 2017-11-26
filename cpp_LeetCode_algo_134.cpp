#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    if(gas.size()==1 && cost[0]<=gas[0]) return 0;

    vector<int> netGasCost(gas.begin(), gas.end());
    for(int i=0;i<netGasCost.size();i++){
        netGasCost[i] -= cost[i];
    }

    for(int i=0;i<netGasCost.size();i++){
        if(netGasCost[i]>=0){
            int acc = 0;
            int j=i;
            // we keep adding, if the value < 0, it means we can't use anyone within i~j
            while( (acc+=netGasCost[j]) >= 0){
                j = (j+1) % netGasCost.size();
                if(j == i){
                    // reach to circle end
                    return i;
                }
            }
            // impossible for idx i ~ j;
            if(i<j){
                // from i to j, they are impossible, and j is still within i:end
                i=j;
            }
            else{
                // from i to j, they are impossible, and j is looped back before i, then it is impossible
                return -1;
            }
        }
    }

    return -1;
}
