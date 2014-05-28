class Solution {
public:
    string convert(string s, int nRows) {
        string ss = s;
        if ( nRows == 1 )
            return ss;
        int i = 0;
        int row = 0;
        int base = 2*nRows - 2;

        char a[nRows][s.size()/base*2+2];
        int flag[nRows];
        memset ( a, '\0', sizeof(a) );
        memset ( flag, 0, sizeof(flag) );

        int j = 0;
        int k = 0;
        for ( i = 0; i < s.size(); i++ ) {
            if ( i%base < nRows )
                row = i%base%nRows;
            else
                row = nRows - i%base%nRows - 2;

            a[row][flag[row]] = s[i];
            flag[row]++;

//            for( k = 0; k < nRows; k++){
//                for( j = 0; j < flag[k]; j++)
//                    cout<<a[k][j];
//                cout<<endl;
//            }

        }

        int cnt = 0;
        for( i = 0; i < nRows; i++){
            for( j = 0; j < flag[i]; j++){
            //    cout<<a[i][j];
            }
            //cout<<endl;
            strncpy( &ss[cnt] , a[i], flag[i] );
            cnt += flag[i];
        }
        return ss;
    }
};
