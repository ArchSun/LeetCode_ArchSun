class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // just two lines, AC.
        // int*  ret = lower_bound( A, A+n, target);
        // return ret-A;
        
        //what shall we do? As follows.
        int left = 0;
        int right = n-1;
        int mid = 0;
        while( left<=right ) {
            mid = (left+right)/2;
            if( A[mid]==target)
                return mid;
            else if( A[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        return right+1;
    }
};
