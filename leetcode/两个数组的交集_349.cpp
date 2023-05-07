// 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0){return result;}
        unordered_map<int, int> hash;
        for (int c : nums1){
            hash[c]++;
        }

        for (int s : nums2){
            if (hash.count(s) && hash[s] > 0){
                result.push_back(s);
                hash[s] = 0;
            }
        }
        return result;
    }
};
