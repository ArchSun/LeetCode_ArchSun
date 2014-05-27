#include <iostream>
using namespace std;

// use kmp algorithm to find substr p in str s
void getNext ( int* next, string p )
{
    int j = 0;
    int k = -1;
    next[0] = -1;
    while ( j < p.size()-1 ) {
        if ( k == -1 || p[j] == p[k]  ) {
            j++;
            k++;
            next[j] = k;
        }
        else {
            k = next[k];
        }

    }
}
int kmp ( string s, string p ){
    int i = 0;
    int j = 0;
    int next [p.size()];
    getNext( next, p );

    while ( i < s.size() && j < p.size() ){
        if ( j < 0 || s[i]==p[j] ){
            i++;
            j++;
        }
        else
            j = next[j];
    }

    if ( j == p.size())
        return i - p.size();
    else
        return -1;
}


int main()
{
    cout << "Hello world!" << endl;
    string s = "aaabb";
    string p = "aa";
    cout << kmp(s,p) <<endl;
    return 0;
}
