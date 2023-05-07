// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> hash(nums1.begin(), nums1.end());
        for (int c : nums2){
            if (hash.find(c) != hash.end()){
                result.insert(c);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
