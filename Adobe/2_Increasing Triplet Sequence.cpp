/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/increasing-triplet-subsequence/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> mn(n),mx(n);
        mn[0]=nums[0],mx[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            mn[i]=min(mn[i-1],nums[i]);
            mx[n-i-1]=max(mx[n-i],nums[n-i-1]);
        }
        for(int i=1;i<n-1;i++){
            if(mn[i-1]<nums[i] && nums[i]<mx[i+1]){
                return true;
            } 
        }
        return false;
    }
};