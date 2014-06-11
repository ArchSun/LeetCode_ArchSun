class Solution {
public:
    bool canJump(int A[], int n) {
        if( n==0 )
            return false;
        int step=A[0];
        int i = 0;
        for( i=1; i<n; i++) {
            if( step>0) {
                step--;
                step=max( step, A[i]);
            }
            else
                return false;
        }
        return true;
    }
};
