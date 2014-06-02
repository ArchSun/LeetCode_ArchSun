class Solution {
public:
    void dfs( vector<string> &ret, string &tmp, int l, int r, int n) {
        if( l==n && r==n) {
            ret.push_back(tmp);
            return;
        }
        if( l<n) {
            tmp.append( 1, '(');
            dfs( ret, tmp, l+1, r, n);
            tmp.resize(tmp.size()-1);
        }
        if( l>r) {
            tmp.append( 1, ')');
            dfs( ret, tmp, l, r+1, n);
            tmp.resize(tmp.size()-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        string tmp = "";
        vector<string> ret;
        dfs( ret, tmp, 0, 0, n);
        return ret;
    }
};
