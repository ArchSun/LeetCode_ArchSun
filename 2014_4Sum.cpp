class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<int> four(4,0);
        if(num.size()<4)
            return ret;
        int i,j,l,r;
        int tmp = 0;

        sort(num.begin(), num.end());
        for( i=0; i<num.size()-3; i++){
            if ( i>0 && num[i]==num[i-1])
                continue;
            for( j=i+1; j<num.size()-2; j++){
                if( j>0 && num[j]==num[j-1])
                    continue;
                l = j+1;
                r = num.size()-1;
                while(l<r){
                    if( l>j+1 && num[l]==num[l-1]){
                        l++;
                        continue;
                    }
                    if( r<num.size()-1 && num[r]==num[r+1]){
                        r--;
                        continue;
                    }
                    tmp = num[i]+num[j]+num[l]+num[r]-target;
                    if (tmp==0){
                        four[0]=num[i];
                        four[1]=num[j];
                        four[2]=num[l];
                        four[3]=num[r];
                        ret.push_back(four);
                        l++;
                    }
                    else if(tmp>0)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ret;
    }
};
