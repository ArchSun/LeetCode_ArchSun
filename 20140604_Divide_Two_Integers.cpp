class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once.
        unsigned a = dividend;
        unsigned b = divisor;
        unsigned ret = 0;
        long long c = b;
        int i = 0;
        while( a>=b) {
      		c = b;
      		for( i=0; a>=c; i++ ) {
      			a -= c;
      			ret += 1<<i;
      			c <<= 1;
      		}
        }
        
        return (dividend^divisor)>>31? 0-ret: ret;
    }
};
