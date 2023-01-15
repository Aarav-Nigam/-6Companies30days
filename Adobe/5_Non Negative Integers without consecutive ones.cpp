/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
//https://www.youtube.com/watch?v=4OL7WdGKC1Y
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0) {
            if (num&(1<<k)) {
                ans += f[k];
                if (pre_bit) return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            --k;
        }
        return ans+1;
    }
};