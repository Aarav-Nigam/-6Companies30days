/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/rotate-function/description/
*/
#include<vector>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        //Declaring variables
        int mx=0,sum=0,cur;
        int n=nums.size();

        //Looping to get the sum as well as multiplied sum
        for(int i=0;i<n;i++){
            mx+=i*nums[i];  
            sum+=nums[i];
        }
        cur=mx;

        //Calculating other multiplied sum values by the formula=>{next=prev+sum-last_elem*n}
        //Formula is created by intuition
        for(int i=n-1;i>=0;i--){
            cur=cur+sum-n*nums[i];
            mx=max(mx,cur);
        }
        return mx;
    }
};