class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> pos;
        int ret = 0;
        int i = 0;
        for( i=0; i<s.size(); i++) {
            if( s[i]=='(') {
                st.push('(');
                pos.push(i);
            }
            else if( !st.empty() && st.top()=='(') {
                st.pop();
                pos.pop();
                ret = max( ret, st.empty()? i+1: i-pos.top());
            }
            else {
                st.push(')');
                pos.push(i);
            }
        }
        return ret;
    }
};
