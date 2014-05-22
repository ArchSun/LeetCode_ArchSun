class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) { 
        
        map<int, int> indexnum;
        map<int, int>::iterator  mapiter;
        vector<int> ret;
        
        for ( vector<int>::iterator iter=numbers.begin(); iter!=numbers.end(); iter++ ){
            
            mapiter = indexnum.find( target - *iter );
            if ( mapiter != indexnum.end() ) {
                ret.push_back( mapiter->second );
                ret.push_back( iter-numbers.begin()+1 );
                return ret;
            }
            
            mapiter = indexnum.find( *iter );
            if ( mapiter == indexnum.end() ) {
                indexnum.insert( pair<int, int> (*iter, iter-numbers.begin()+1 ));
            }
            
        }
    }
};
