class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int left = 0,right = n-1;
        //������߽�
        int ret_left = 0;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        //�ж�������
        if(nums[left] == target) ret_left = left;
        else return {-1,-1};
        //��������ָ��
        left = 0,right = n-1;
        //���ұ߽�
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        //�����ж��Ƿ����target������߽�Ϳ϶����ұ߽硣��ǰ��left�����ұ߽�
        return {ret_left,left};
    
    }
};

//��stl�Ķ����㷨lower_bound upper_bound
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        auto left = lower_bound(nums.begin(),nums.end(),target);
        if(left == nums.end() || *left != target) return {-1,-1};
        auto right = upper_bound(nums.begin(),nums.end(),target);
        int start = left - nums.begin();
        int end = right - nums.begin() - 1;
        return {start, end};
    }
}; 
