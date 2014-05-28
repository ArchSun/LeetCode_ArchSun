class Solution {
public:
    int atoi(const char *str) {
        double ret = 0;
        bool flag = false;
        bool hasNum = false;
        while ( *str==32 )
            str++;
        if ( *str==43 )
            str++;
        else if ( *str==45 ){
            flag = true;
            str++;
        }
        else
            str = str;

        while( *str>=48&&*str<=57 ) {
            hasNum = true;
            ret = (*str-48) + ret*10;
            if ( !flag ){
                if ( ret > 2147483647)
                    return 2147483647;
            }
            else {
                if ( ret > 2147483648)
                return -2147483648;
            }
            str++;
        }

        if ( hasNum ) {
            ret = flag? -ret : ret;
            return ret;
        }
        else
            return 0;
    }
};
