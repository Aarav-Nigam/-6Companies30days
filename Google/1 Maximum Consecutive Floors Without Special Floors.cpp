/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans=0;
        for(int i:special){
            ans=max(i-bottom,ans);
            bottom=i+1;
        }
        return max(top-bottom+1,ans);
    }
};