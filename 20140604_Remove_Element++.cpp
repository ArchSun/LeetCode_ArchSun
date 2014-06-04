class Solution {
public:
    int removeElement( int A[], int n, int elem) {
        int i = 0;
        int mvcnt = 0;
        for( i=0; i<n; i++) {
          if( A[i]==elem)
            mvcnt++;
          else
            A[i-mvcnt] = A[i];
        }
        return n-mvcnt;
    }
};
