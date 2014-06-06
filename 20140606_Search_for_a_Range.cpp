class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // equal range
        vector<int> ret;
        pair< int*, int* > range;
        range = equal_range( A, A+n, target);
        //cout<<*(range.first)<<" "<<*(range.second)<<endl;
        if( range.first==range.second ) {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        else {
            ret.push_back( range.first - A);
            ret.push_back( range.second - 1 - A);
        }
        return ret;
    }
};
