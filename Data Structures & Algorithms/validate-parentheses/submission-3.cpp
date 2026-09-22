class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(const char& c: s) {
            if(c == '(' or c == '{' or c == '[') {
                st.push(c);
            }
            else {
                if(c == ')') {
                    if(st.size() > 0 and st.top() == '(') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                if(c == '}') {
                    if(st.size() > 0 and st.top() == '{') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                if(c == ']') {
                    if(st.size() > 0 and st.top() == '[') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return st.size() == 0;
    }
};
