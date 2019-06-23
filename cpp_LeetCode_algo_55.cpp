#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums);

int main(){
    vector<int> nums = {3,2,1,0,4};

    cout << canJump(nums) << endl;

    return 0;
}


/*
    solution: ����bb, ˼· --- ��Χǰ��
*/
bool canJump(vector<int>& nums) {
    if(nums.size()==1) return true;

    int start = 1, end=nums[0];
    while(start <= end){

        int nextStart = end+1;
        for(int j=start; j<nextStart; j++){
            end = max(end, j+nums[j]);
            if(end >= nums.size()-1) return true;
        }

        start = nextStart;
    }

    return false;
}


/*
    ͬ��, ��һ��д��
*/
bool canJump(vector<int>& nums) {
    if(nums.empty()) return true;

    int start = 0;
    int end = 0;
    int nextEnd = end;

    while(start <= end){
        for(; start<=end; start++){
            nextEnd = max(start+nums[start], nextEnd);
        }
        if(nextEnd >= (int)nums.size()-1){
            return true;
        }
        else{
            start = end+1;
            end = nextEnd;
        }
    }

    return false;
}







/*
����֮ǰ�� ��Χǰ�� ��� �����ǰ��Χ�����ҵ���һ����Զ�ķ�Χ���ʹ�����ǰ���Ŀ����ԡ�
��֮�������ǰ��Χ�Ҳ�����Զ�ķ�Χ����˵����ǰ��Χֻ���ڵ�ǰ��Χ���ܣ��Ϳ��ڵ�ǰ��Χ�ˡ�
��Ҳ�Ͳ������������ô����ʧ�ܡ���֮��һֱǰ�����п��ܳɹ���
*/
//bool canJump(vector<int>& nums) {
//    if(nums.empty()) return false;
//
//    int startIdx = 0;
//    int endIdx = 0;
//    int tempIdx;
//    int maxEnd = endIdx;
//    while(endIdx < nums.size()-1){
//        for(tempIdx = startIdx; tempIdx<=endIdx; tempIdx++){
//            //����һ��range����ԶendIdx
//            maxEnd = max(maxEnd, nums[tempIdx]+tempIdx);
//            //�����һ����Χ���ܵĳ���lastidx��˵�����ܵ����
//            if(maxEnd >= nums.size()-1) return true;
//        }
//
//        startIdx = endIdx+1;
//        //�����ǰ��Χ�ҵ�����һ��endidx���ڵ�ǰ��Χ�ڣ�˵���Ϳ��ڵ�ǰ��Χ�ˣ����ܳɹ�
//        if(maxEnd <= endIdx) return false;
//        endIdx = maxEnd;
//    }
//    //ֻ�е�endIdx�ܵ�����ˣ����п�������ѭ�����Ǿ�˵���ܳɹ�
//    return true;
//}
