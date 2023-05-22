// 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
// 示例 1：

// 输入：words = ["bella","label","roller"]
// 输出：["e","l","l"]

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
