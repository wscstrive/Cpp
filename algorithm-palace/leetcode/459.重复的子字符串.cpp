// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

// 示例 1:

// 输入: s = "abab"
// 输出: true
// 解释: 可由子串 "ab" 重复两次构成。

class Solution {
public:
    void getNext(int* next, string& s) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && len % (len - (next[len - 1] )) == 0) {
            return true;
        }
        return false;
    }
};
