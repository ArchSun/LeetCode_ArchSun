class Solution {
public:
    bool isValid (string s) {
        stack<char> matchPair;
        int i = 0;
        for( i=0; i<s.size(); i++){
            if( s[i]=='{'||s[i]=='['||s[i]=='(')
                matchPair.push(s[i]);
            else if( !matchPair.empty() && (s[i]-matchPair.top()) && (abs(s[i]-matchPair.top())<3))
                matchPair.pop();
            else
                return false;
        }
        if(matchPair.empty())
            return true;
        else
            return false;
    }
};
