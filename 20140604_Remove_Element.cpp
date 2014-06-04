struct usrcmp {
    bool operator ()( int x, int y) {
        return x!=y;
    }
};

class Solution {
public:
    int removeElement( int A[], int n, int elem) {
        sort( A, A+n);
        int *first = find( A, A+n, elem);
        //cout<<"first: "<<*first<<endl;
        if( first==A+n)
            return n;
        int *second = adjacent_find( first, A+n, usrcmp());
        //cout<<"sec: "<<*second<<endl;
        if( second==A+n)
            second--;
        second++;
        int len = second-first;
        while( second!=A+n )
            *first++ = *second++;
        return n-len;
    }
};
