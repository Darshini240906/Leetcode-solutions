class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If k is still left, remove from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;

        result = result.substr(i);


      

        return result.empty() ? "0" : result;
    }
};