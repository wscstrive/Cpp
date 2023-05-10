// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
// 在 S 上反复执行重复项删除操作，直到无法继续删除。
// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s){
            if (st.empty()) st.push(c);
            else if (st.top() == c) st.pop();
            else st.push(c);
        }
        
        vector<char> result;
        while (!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return string(result.begin(),result.end());
    }
};
