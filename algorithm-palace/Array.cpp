// 704.二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
};


// 27.移除元素
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto it = nums.begin(); it != nums.end();){
            if (*it == val){
                nums.erase(it);
            }
            else{
                ++it;
            }
        }
        return nums.size();
    }
};


// 977.有序数组的平方
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


// 209.长度最小的子数组
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


// 59.螺旋矩阵II
// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
// 1——2——3
//       |
// 8——9  4
// |     |
// 7——6——5

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        vector<vector<int>> answer(n, vector<int>(n));
        int k = 1;
        while (k <= n * n){
            for (int i = l; i <= r; k++, i++){
                answer[t][i] = k;
            }
            t++;
            for (int i = t; i <= b; k++, i++){
                answer[i][r] = k;
            }
            r--;
            for (int i = r; i >= l; k++, i--){
                answer[b][i] = k;
            }
            b--;
            for (int i = b; i >= t; k++, i--){
                answer[i][l] = k;
            }
            l++;
        }

        return answer;
    }
};

