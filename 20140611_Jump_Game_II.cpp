class Solution {
public:
    int jump(int A[], int n) {
        int cur = 0;
        int next = 0;
        int range = 0;
        int ret = 0;
        int i = 0;
        if( n<=1 )
            return 0;
        while( true ) {
            if( A[cur]==0 )
                return -1;
            ret++;
            if( A[cur]+cur >= n-1 )
                return ret;
            for( i=1; i<=A[cur]; i++ ) {
                if( A[i+cur]+i+cur > range ) {
                    range = A[i+cur] + i+cur;
                    next = i+cur;
                }
            }
            cur = next;
        }
    }
};
