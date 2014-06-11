class Solution {
public:
    double pow(double x, int n) {
        double ret = 1.0;
        bool flag = false;
        if( n<0 ) {
            flag = true;
            n = -n;
        }
        while( n ) {
            if( n%2 )
                ret *= x;
            x *= x;
            n /= 2;
        }
        if( flag )
            return 1.0/ret;
        else
            return ret;
    }
};
