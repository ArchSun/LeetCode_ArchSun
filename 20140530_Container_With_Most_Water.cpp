class Solution {
public:
  int maxArea ( vector<int> & height ) {
    int retMaxArea = 0;
    vector<int>:: iterator lter = height.begin();
    vector<int>:: iterator rter = height.end()-1;
    while( lter<rter ){
      retMaxArea = max( retMaxArea, min(*lter,*rter)*(rter-lter) );
      if (*lter<*rter)
        lter++;
      else
        rter--;
    }
  }
};
