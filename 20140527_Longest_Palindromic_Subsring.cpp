class Solution {
public:
    void getPalindromeLen ( int* p, string spp ){
        int i = 0;
        int mx = 1;
        int id = 0;
        p[0] = 1;

        for ( i = 1; i < spp.size(); i++ ) {
            if ( mx > i )
                p[i] = min ( p[2*id-i], mx - i );
            else
                p[i] = 1;
            while ( spp[i+p[i]] == spp[i-p[i]] )
                p[i]++;

            if ( p[i]+i > mx ) {
                mx = p[i]+i;
                id = i;
            }
        }
    }

    string longestPalindrome(string s) {
        string spp ( 2*s.size()+1, '#');
        int i = 0;
        for ( i = 0; i < spp.size(); i++ ){
            if ( i%2 )
                spp[i] = s[i/2];
        }

        int p[spp.size()];
        getPalindromeLen( p, spp );

        int longest = 0;
        int longestid = 0;
        for ( i = 0; i < spp.size(); i++ ){
            if ( p[i] > longest ){
                longest = p[i];
                longestid = i;
            }
        }

        //cout <<spp<<endl;
        //cout <<longest << "   " << longestid<<endl;
        //cout <<longestid/2-longest/2<< "   " << longest-1 <<endl;
        //cout <<s<<endl;

        string ret;
        // # in the middle
        if ( longestid%2==0 )
            ret = s.substr( longestid/2-longest/2, longest-1 );
        else    // num in the middle
            ret = s.substr( longestid/2-longest/2+1, longest-1 );

        //cout<<ret<<endl;
        return ret;
    }
};
