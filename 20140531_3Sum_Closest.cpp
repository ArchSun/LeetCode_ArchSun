class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret = INT_MAX;
        int ltgt = INT_MIN;
        int rtgt = INT_MAX;
        double t2r = 0;
        double l2t = 0;
        bool rflag = false;
        bool lflag = false;

        vector<int>::iterator iter;
        vector<int>::iterator lter;
        vector<int>::iterator rter;

        sort(num.begin(), num.end());
        for( iter=num.begin(); iter!=num.end()-2; iter++ ){
            //cout<<"iter "<<*iter<<endl;
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
                ret = *iter+*lter+*rter;
                // cout<<"iter "<<*iter<<" lter "<<*lter<<"    rter "<<*rter<<"    ret "<<ret<<endl;
                if( ret==target )
                    return ret;
                else if( ret>target ){
                    rflag = true;
                    rtgt = min(rtgt,ret);
                    rter--;
                   // cout<<"rtgt "<<rtgt<<endl;
                }
                else {
                    lflag = true;
                    ltgt = max(ltgt,ret);
                    lter++;
                   // cout<<"ltgt "<<ltgt<<endl;
                }
            }
        }
        if (!rflag)
            return ltgt;
        if (!lflag)
            return rtgt;
        t2r = fabs(rtgt-target);
        l2t = fabs(target-ltgt);
        //cout<<t2r<<"    "<<l2t<<endl;
        ret = t2r>l2t? ltgt: rtgt;
        return ret;
    }
};
