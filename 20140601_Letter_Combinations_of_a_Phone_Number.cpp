class Solution {
public: 
  void dfs (vector<string> &ret, string &tmp, string &digits, int cur){
    if ( cur==digits.size()) {
      ret.push_back(tmp);
      return;
    }
    int i;
    int k = digits[cur]-'0';
    for( i=0; i<mp[k].size(); i++) {
      tmp.append(1, mp[k][i]);
      dfs(ret, tmp, digits, cur+1);
      tmp.resize(tmp.size()-1);
    }
  }
  vector<string> letterCombinations(string digits){
    vector<string> ret;
    string tmp;
    //dfs(ret, tmp, digits, cur);
    dfs(ret, tmp, digits, 0);
    return ret;
  }
private:
  string mp[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};
