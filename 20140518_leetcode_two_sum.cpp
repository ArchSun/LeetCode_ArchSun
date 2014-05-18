#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node{
    int ind,val;
};

bool comp(const node& a, const node & b){return a.val<b.val;}

class Solution {

public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // input is numbers and target
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> arr(numbers.size());
        // get the index before sorting
        for(int i=0;i<numbers.size();i++){
            arr[i].ind = i;
            arr[i].val = numbers[i];
        }

        sort(arr.begin(),arr.end(),comp);
        // initialize to empty
        vector<int> ret;

        int left = 0, right = numbers.size()-1;
        // perfect, two heads go middle
        // function at == []
        while(left < right){
            if( arr[left].val+arr[right].val == target) break;
            else if( arr[left].val +arr[right].val > target) right--;
            else left++;
        }
        //
        if(arr[left].ind > arr[right].ind){
            int tmp = left;
            left = right;
            right = tmp;
        }
        ret.push_back(arr[left].ind+1);
        ret.push_back(arr[right].ind+1);


        return ret;
    }
};

int main( ){

    Solution s;
    vector<int> ret;
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(7);
    numbers.push_back(11);
    numbers.push_back(5);
    int target = 9;

    ret=s.twoSum(numbers, target);
    cout<< "index1 = "<<ret[0]<<", index2 = "<<ret[1]<<endl;
}
