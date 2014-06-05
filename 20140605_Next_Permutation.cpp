class Solution {
// reverse swap can be useed
// 5--3 1 2
// 5 = (3-1)*2! + (1-1)*1! + (2-1)*0!
public:
    void nextPermutation(vector<int> &num) {
       int i = 0;
       int len = num.size();
       if( len<2 ) return;
       int start = 0;
       int tmp = 0;
       for( i=len-1; i>0; i--){
            if( num[i]>num[i-1] )
                break;
       }
       start = i;
       if( start) {
           for( i=len-1; i>start; i--) {
                if( num[i]>num[start-1])
                    break;
           }
           tmp = num[start-1];
           num[start-1] = num[i];
           num[i] = tmp;
       }
       while( start<len-1 ){
            tmp = num[start];
            num[start] = num[len-1];
            num[len-1] = tmp;
            start++;
            len--;
       }
    }
};

