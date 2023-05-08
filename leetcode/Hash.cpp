// 242.字母异位词
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++){
            hash[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++){
            if (hash[i] != 0){
                return false;
            }
        }
        return true;
    }
};

// 1002.查找公用字符
// 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        if (words.size() == 0){return result;}
        int hash[26] = {0};
        for (char c : words[0]){
            hash[c - 'a']++;
        }

        int otherHash[26] = {0};
        for (string c : words){
            memset(otherHash, 0, 26 * sizeof(int));
            for (char s : c){
                otherHash[s - 'a']++;
            }

            for (int i = 0; i < 26; i++){
                hash[i] = min(hash[i], otherHash[i]);
            }
        }

        for (int i = 0; i < 26; i++){
            while (hash[i] != 0){
                string s(1, i + 'a');
                result.push_back(s);
                hash[i]--;
            }
        }
        return result;
    }
};


// 349.两个数组的交集
// 给定两个数组 nums1 和 nums2 ，返回它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

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


// 202.快乐数
// 编写一个算法来判断一个数 n 是不是快乐数。

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash;
        while (n > 0){
            int result = 0;
            while (n > 0){
                result += (n % 10) * (n % 10);
                n = n / 10;
            }

            if (result == 1){
                return true;
            }
            else if(hash.find(result) != hash.end()){
                return false;
            }
            hash.insert(result);
            n = result;
        }
        return false;
    }
};


// 1.两数之和
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

// 454.四数相加II
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

// 383.赎金信
// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。
// magazine 中的每个字符只能在 ransomNote 中使用一次。

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;
        int counts = 0;
        for (char c : magazine){
            hash[c]++;
        }

        for (char s : ransomNote){
            if (hash.count(s) && hash[s] > 0){
                hash[s]--;
                counts++;
            }
        }
        return counts == ransomNote.size();
    }
};

// 15.三数之和
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
// 你返回所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){

            if (nums[0] > 0){
                return result;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] > 0){
                    right--;
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++;
                }
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]){left++;}
                    while (left < right && nums[right] == nums[right - 1]){right--;}

                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};


// 18.四数之和
// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){

            if (nums[i] > target && nums[i] >= 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < nums.size(); j++){
                
                if (nums[i] + nums[j] > target && nums[j] >= 0) break;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right){
                    
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left ++;
                    else{
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
