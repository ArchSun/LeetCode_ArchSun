class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        vector<int>::iterator iter;
        vector<int>::iterator lter;
        vector<int>::iterator rter;
        sort(num.begin(), num.end());
        int minGap = num[0]+num[1]+num[2]-target;
        int tmp = 0;
        for( iter=num.begin(); iter!=num.end()-2; iter++ ){
            if( iter>num.begin() && *iter==*(iter-1))
                continue;
            lter = iter + 1;
            rter = num.end() - 1;
            while(lter<rter){
                if( lter>iter+1 && *lter==*(lter-1)) {
                    lter++;
                    continue;
                }
                if( rter<num.end()-1 && *rter==*(rter+1)){
                    rter--;
                    continue;
                }
                tmp = *iter+*lter+*rter-target;
                if( tmp==0 )
                    return target;
                else if( tmp>0 ){
                    minGap = abs(minGap)<tmp? minGap: tmp;
                    rter--;
                }
                else {
                    minGap = abs(minGap)<0-tmp? minGap: tmp;
                    lter++;
                }
            }
        }
        return minGap+target;
    }
};
