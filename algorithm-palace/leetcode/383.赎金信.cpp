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
