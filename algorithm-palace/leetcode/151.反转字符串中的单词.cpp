// 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。


// 示例 1：

// 输入：s = "the sky is blue"
// 输出："blue is sky the"

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void reverseSpace(string& s){
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (index != 0) s[index++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[index++] = s[i++];
                }
            }
        }
        s.resize(index);
    }
    string reverseWords(string s) {
        reverseSpace(s);
        reverse(s, 0, s.size() - 1);
        int k = 0;
        for (int i = 0; i <= s.size(); i++) {
            if  (i == s.size() || s[i] == ' ') {
                reverse(s, k, i - 1);
                k = i + 1;
            }
        }
        return s;
    }
};
