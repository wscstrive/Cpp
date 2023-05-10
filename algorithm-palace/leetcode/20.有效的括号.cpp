// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 每个右括号都有一个对应的相同类型的左括号。

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') stk.push(')');
            else if (s[i] == '[') stk.push(']');
            else if (s[i] == '{') stk.push('}');
            else if (stk.empty()) return false;
            else if (stk.top() != s[i]) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};
