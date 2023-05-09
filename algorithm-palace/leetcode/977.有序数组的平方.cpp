// 给你一个按 非递减顺序 排序的整数数组 nums，返回每个数字的平方 组成的新数组，要求也按非递减顺序排序。

class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
