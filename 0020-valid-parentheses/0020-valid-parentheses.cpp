class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty() && (c == ')' || c == ']' || c == '}'))
                return false;
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if ((c == ')' && st.top() == '(') ||
                     (c == ']' && st.top() == '[') ||
                     (c == '}' && st.top() == '{'))
                     st.pop();
                     else return false;
        }
        return st.empty() ?true :false;
    }
};