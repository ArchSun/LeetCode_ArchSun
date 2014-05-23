class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.length() == 0) {
            return 0;
        }
        bool vis[256];
        memset(vis, false, sizeof(vis));
        int ans = 1, l = 0, r = 0;
        while ( r < s.length()){
            if ( !vis[s[r]] ){
                vis[s[r]]=true;
                r++;
            }
            else {
                ans = max (ans, r-l);
                while(s[l]!=s[r]){
                    vis[s[l]]=false;
                    l++;
                }
                l++;
                r++;
            }
        }
        ans = max (ans, r-l);
        return ans;
    }
};
