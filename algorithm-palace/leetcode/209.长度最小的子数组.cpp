// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

// c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT32_MAX;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                result = r - l + 1 < result ? r - l + 1 : result;
                sum -= nums[l++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

// python
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l = 0
        sum = 0
        result = inf
        for r in range(len(nums)):
            sum += nums[r]
            while sum >= target:
                if r - l + 1 < result:
                    result = r - l + 1
                else:
                    result = result
                sum -= nums[l]
                l += 1
        if result == inf:
            return 0
        else:
            return result
