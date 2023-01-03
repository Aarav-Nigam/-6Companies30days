/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/largest-divisible-subset/description/
*/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size(), mx = -1, mxi = -1;// Declaring variables to save values of max val,index,size
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);


        sort(nums.begin(), nums.end()); //sorting so that we don't have to worry about a[i]%b[i]==0
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {

                if ((nums[i] % nums[j] == 0) && dp[j] >= dp[i]) //Based on the condition saving path and maintaining max value in dp
                {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
            if (dp[i] > mx)
            {
                mx = dp[i];
                mxi = i;
            }
            //saving maximum answer 
        }

        vector<int> ans;
        while (mxi != -1)
        {
            ans.push_back(nums[mxi]); //saving thr path using trace vector
            mxi = trace[mxi];
        }
        return ans;
    }
};