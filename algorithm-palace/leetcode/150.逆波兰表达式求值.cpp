// 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
// 请你计算该表达式。返回一个表示表达式值的整数。

// 示例 1：
// 输入：tokens = ["2","1","+","3","*"]
// 输出：9
// 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for (string c : tokens){
            if (c == "+" || c == "-" || c == "/" || c == "*"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                if (c == "+") result = b + a;
                if (c == "-") result = b - a;
                if (c == "/") result = b / a;
                if (c == "*") result = b * a;
                st.push(result);         
            }
            else st.push(stoll(c));
        }
        int _result = st.top();
        st.pop();
        return result;
    }
};
