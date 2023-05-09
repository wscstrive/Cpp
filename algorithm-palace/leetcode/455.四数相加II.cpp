// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int counts = 0;
        unordered_map<int, int> hash;
        for (auto c : nums1){
            for (auto s : nums2){
                hash[c + s]++;
            }
        }

        for (auto c : nums3){
            for (auto s : nums4){
                if (hash.count(0 - (c + s))){
                    counts += hash[0 - (c+s)];
                }
            }
        }

        return counts;
    }
};
