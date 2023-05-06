// 给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        if (words.size() == 0){return result;}
        int hash[26] = {0};
        for (int i = 0; i < words[0].size(); i++){
            hash[words[0][i] - 'a']++;
        }

        int otherHash[26] = {0};
        for (int n = 1; n < words.size(); n++){
            memset(otherHash, 0, 26 * sizeof(int));
            for (int i = 0; i < words[n].size(); i++){
                otherHash[words[n][i] - 'a']++;
            }

            for (int j = 0; j < 26;j++){
                hash[j] = min(hash[j], otherHash[j]);
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
