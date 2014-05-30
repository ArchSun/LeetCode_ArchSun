class Solution {
public:
  string longestCommonPrefix(vector<string> &strs){
    vector<string>:: iterator = strs.begin();
    if (iter==strs.end())
      return "";
    string ret = *iter;
    int i = 0;
    bool flag = false;
    while(i<ret.size()){
      for( iter=strs.begin()+1; iter!=strs.end(); iter++){
        if (ret[i]^(*iter)[i]){
          flag = true;
          break;
        }
      }
      if(flag)
        break;
      i++;
    }
    return ret.substr(0, i);
  }
};
