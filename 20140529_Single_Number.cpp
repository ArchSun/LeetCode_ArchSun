class Solution {
public:
  int singleNumber (int A[], int n){
    int result = 0;
    while ( n-- )
      result ^= A[n];
    return result;
  }
};
