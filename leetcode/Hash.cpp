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

