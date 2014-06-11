class Solution {
public:
    void clockwiseSwap(int &a, int &b, int &c, int &d) {
        int tmp = a;
        a = d;
        d = c;
        c = b;
        b = tmp;
    }
    void rotate(vector<vector<int> > &matrix) {
        int i = 0;
        int j = 0;
        int n = matrix.size();
        if( n<2 )
            return;
        for( i=0; i<n/2; i++) {
            for( j=i; j<n-1-i; j++)
            clockwiseSwap( matrix[i][j], matrix[j][n-1-i], matrix[n-1-i][n-1-j], matrix[n-1-j][i]);
        }
    }
};
