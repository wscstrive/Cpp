// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int dist = INT32_MAX;
        int l = 0;
        int sum = 0;
        for (int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while (sum >= target){
                dist = dist > (r - l + 1) ? (r - l + 1) : dist;
                sum -= nums[l++];
            }
        }
        return dist == INT32_MAX ? 0 : dist;
    }
};
