class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        int left = 0,right = n-1;
        //先求左边界
        int ret_left = 0;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        //判断相遇点
        if(nums[left] == target) ret_left = left;
        else return {-1,-1};
        //重置两个指针
        left = 0,right = n-1;
        //求右边界
        while(left < right)
        {
            int mid = (left + right + 1) / 2;
            if(nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        //不用判断是否等于target，有左边界就肯定有右边界。当前的left就是右边界
        return {ret_left,left};
    
    }
};

//用stl的二分算法lower_bound upper_bound
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
