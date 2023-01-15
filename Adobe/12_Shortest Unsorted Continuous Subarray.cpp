/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp=nums;
        int n=nums.size();
        sort(temp.begin(),temp.end());
        int l=0,r=n-1;
        while(l<n && nums[l]==temp[l]){
            l++;
        }
        if(l==n) return 0;
        while(r>0 && nums[r]==temp[r]){
            r--;
        }
        return r-l+1;
    }
};