#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums);

int main(){
    vector<int> nums = {3,2,1,0,4};

    canJump(nums);

    return 0;
}


/*
����֮ǰ�� ��Χǰ�� ��� �����ǰ��Χ�����ҵ���һ����Զ�ķ�Χ���ʹ�����ǰ���Ŀ����ԡ�
��֮�������ǰ��Χ�Ҳ�����Զ�ķ�Χ����˵����ǰ��Χֻ���ڵ�ǰ��Χ���ܣ��Ϳ��ڵ�ǰ��Χ�ˡ�
��Ҳ�Ͳ������������ô����ʧ�ܡ���֮��һֱǰ�����п��ܳɹ���
*/
bool canJump(vector<int>& nums) {
    if(nums.empty()) return false;

    int startIdx = 0;
    int endIdx = 0;
    int tempIdx;
    int maxEnd = endIdx;
    while(endIdx < nums.size()-1){
        for(tempIdx = startIdx; tempIdx<=endIdx; tempIdx++){
            //����һ��range����ԶendIdx
            maxEnd = max(maxEnd, nums[tempIdx]+tempIdx);
            //�����һ����Χ���ܵĳ���lastidx��˵�����ܵ����
            if(maxEnd >= nums.size()-1) return true;
        }

        startIdx = endIdx+1;
        //�����ǰ��Χ�ҵ�����һ��endidx���ڵ�ǰ��Χ�ڣ�˵���Ϳ��ڵ�ǰ��Χ�ˣ����ܳɹ�
        if(maxEnd <= endIdx) return false;
        endIdx = maxEnd;
    }
    //ֻ�е�endIdx�ܵ�����ˣ����п�������ѭ�����Ǿ�˵���ܳɹ�
    return true;
}
