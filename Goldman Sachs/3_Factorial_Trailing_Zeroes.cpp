/*
Name:Aarav Nigam
https://leetcode.com/problems/valid-square/
*/
/*
Calculating no. of 5
*/
#include<math.h>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=1;i<=6;i++){
            ans+=n/pow(5,i);
        }
        return ans;
    }
};
