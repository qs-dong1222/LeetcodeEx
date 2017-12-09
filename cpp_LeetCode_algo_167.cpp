vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ans;
    if(numbers.empty()) return ans;

    int lidx = 0;
    int ridx = numbers.size()-1;

    while(lidx < ridx){
        int sum = numbers[lidx] + numbers[ridx];
        if(sum == target){
            ans.push_back(lidx+1);
            ans.push_back(ridx+1);
            return ans;
        }
        else if(sum < target){
            lidx++;
        }
        else{
            ridx--;
        }
    }

    return ans;
}
