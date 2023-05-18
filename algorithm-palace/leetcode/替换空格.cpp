// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."

class Solution {
public:
    string replaceSpace(string s) {
        int counts = 0;
        for (char c : s) {
            if (c == ' ') {
                counts += 3;
                continue;
            }
            counts++;
        }
        
        string result(counts, ' ');
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                result[index++] = '%';
                result[index++] = '2';
                result[index++] = '0';
                continue;
            }
            result[index++] = s[i];
        }
        return result;
    }
};
