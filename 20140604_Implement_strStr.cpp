class Solution {
public:
  void getNext( int* next, char* needle, int n) {
    int i = 0;
    int j = -1;
    next[0] = -1;
    while( i<n-1 ) {
      if( j==-1 || needle[i] == needle[j] )
        next[++i] = ++j;
      else
        j = next[j];
    }
  }
  char* strStr ( char* haystack, char* needle) {
    int len0 = strlen( haystack);
    int len1 = strlen( needle);
    int i = 0;  
    int j = 0;
    int *next = new int[len1];
    getNext( next, needle, len1);
    
    while( i<len0 && j<len1) {
      if( j==-1 || haystack[i] == needle[j]) {
        i++;
        j++;
      }
      else
        j = next[j];
    }
    delete [] next;
    if( j==len1)
      return haystack+i-j;
    else
      return NULL;
  }

};
