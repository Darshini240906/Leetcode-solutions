class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Opening brackets → push
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Closing brackets → check
            else {
                if (st.empty()) return false;

                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};
