/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
*/
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int GcdOfArray(vector<int>& arr, int idx){
        if (idx == arr.size() - 1) {
            return arr[idx];
        }
        int a = arr[idx];
        int b = GcdOfArray(arr, idx + 1);
        return __gcd(a, b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd=GcdOfArray(numsDivide,0);
        int i=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(;i<n;i++){
            if(gcd<nums[i]){
                return -1;
            }
            if(gcd%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};