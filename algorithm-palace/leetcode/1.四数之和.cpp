// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.count(target - nums[i])){
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
            }
            hash[nums[i]] = i;
        }

        return result;
    }
};
