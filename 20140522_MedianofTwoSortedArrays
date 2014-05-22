class Solution {

	public:

    double findTopKinAandB(int A[], int m, int B[], int n, int topK){
        if (m>n)
            return findTopKinAandB( B, n, A, m, topK);
        if (m==0)
            return (double)(B[topK-1]);
        if (topK==1)
            return (double)(min(A[0], B[0]));

        int amid = min(topK/2, m);
        int bmid = topK - amid;

        if( A[amid-1] > B[bmid-1])
            return findTopKinAandB( A, m, B+bmid, n-bmid, topK-bmid);
        if ( A[amid-1] < B[bmid-1])
            return findTopKinAandB( A+amid, m-amid, B, n, topK-amid);

        return (double)(A[amid-1]);

    }

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m+n)%2)
            return findTopKinAandB(A,m,B,n,(m+n+1)/2);
        else
            return 0.5*(findTopKinAandB(A,m,B,n,(m+n)/2) + findTopKinAandB(A,m,B,n,(m+n)/2+1));
	}
};
