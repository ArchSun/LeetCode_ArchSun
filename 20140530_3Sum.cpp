class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        if (num.size()<3)
            return ret;
        vector<int> tmp(3,0);
        sort( num.begin(), num.end());

        vector<int>::iterator iter;
        vector<int>::iterator lter;
        vector<int>::iterator rter;

        for ( iter=num.begin(); iter!=num.end()-2; iter++) {
            if ( iter>num.begin()&&(*iter)==(*(iter-1)) )
                continue;
            lter = iter+1;
            rter = num.end()-1;
            while(lter<rter){
                if ( lter>iter+1 && *lter==*(lter-1) ){
                    lter++;
                    continue;
                }
                if ( rter<num.end()-1 && *rter==*(rter+1) ){
                    rter--;
                    continue;
                }
                if ( *lter+*rter+*iter==0 ) {
                    tmp[0]=*iter;
                    tmp[1]=*lter;
                    tmp[2]=*rter;
                    ret.push_back(tmp);
                    lter++;
                }
                else if ( *lter+*rter+*iter>0 )
                    rter--;
                else
                    lter++;
            }
        }
//        vector<vector<int> >:: iterator iiter;
//        for( iiter=ret.begin(); iiter!=ret.end();iiter++)
//            cout<<"outret: "<<(*iiter).size()<<" "<<(*iiter)[0]<<" "<<(*iiter)[1]<<" "<<(*iiter)[2]<<endl;
        return ret;
    }
};
