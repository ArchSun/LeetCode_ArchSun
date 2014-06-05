class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once.
		map<string, int> wordSet;
		map<string, int> cmpSet;
		vector<int> ret;
		int i = 0;
		int vecLSize = L.size();
		int wordSize = L[0].size();
		for( i=0; i<vecLSize; i++)
		    wordSet[L[i]]++;
		int j = 0;
		string word;
		// warning type of S.size() !!!!
		for( i=0; i<=(int)S.size()-vecLSize*wordSize; i++) {
		    cmpSet.clear();
		    for( j=0; j<vecLSize; j++) {
		        word = S.substr( i+j*wordSize, wordSize);
		        if( wordSet.find(word) == wordSet.end())
		            break;
		        cmpSet[word]++;
		        if( wordSet[word]<cmpSet[word])
		            break;
		    }
		    if( j==vecLSize)
		        ret.push_back(i);
		}
		return ret;
    }
};
