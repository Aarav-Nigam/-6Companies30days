/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/maximum-length-of-repeated-subarray/
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    //same as longest common substring
    public:
    int findLength(vector<int> A, vector<int>B) {
        if(A.empty() ||B.empty()) return 0;
        int m = A.size();
        int n = B.size();
        int mx = 0;
        //dp[i][j] is the length of longest common subarray ending with nums[i] and nums[j]
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i = 0;i <= m;i++){
            for(int j = 0;j <= n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
                else{
                    if(A[i - 1] == B[j - 1]){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        mx = max(mx,dp[i][j]);
                    }
                }
            }
        }
        return mx;
    }
};