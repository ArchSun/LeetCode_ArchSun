class Solution {
// KMP Algorithm !!! YES
public:
    void mvGen( int *pMv, char* needle, int len) {
        int i = 0;
        int j = -1;
        pMv[0] = -1;
        while( i<len-1) {
            if( j==-1 || needle[i] == needle[j] )
                pMv[++i] = ++j;
            else
                j = pMv[j];
        }
    }
    char *strStr(char *haystack, char *needle) {
        int len = strlen(needle);
        int l = strlen(haystack);
        int* pMv = new int[len];
        mvGen( pMv, needle, len);
        int i = 0;
        int j = 0;
        while( i<l && j<len ){
            if( j==-1 || haystack[i]==needle[j] ) {
                i++;
                j++;
            }
            else
                j = pMv[j];
        }
        delete [] pMv;
        if( j==len)
            return haystack + i - j;
        else
            return NULL;  
    }
};
