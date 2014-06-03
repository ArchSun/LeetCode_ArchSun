class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int mvcnt = 0;
        int i = 0;
        for( i=1; i<n; i++) {
            if( A[i]==A[i-1])
                mvcnt++;
            else if( mvcnt && A[i]!=A[i-1])
                A[i-mvcnt] = A[i];
        }
        return n-mvcnt;
    }
};
