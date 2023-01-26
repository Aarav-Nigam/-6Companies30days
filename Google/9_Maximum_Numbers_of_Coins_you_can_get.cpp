/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n3=piles.size();
        int n=n3/3;
        int ans=0;
        make_heap(piles.begin(),piles.end());
        for(int i=0;i<n;i++){
            pop_heap(piles.begin(),piles.end());
            piles.pop_back();
            ans+=piles.front();
            pop_heap(piles.begin(),piles.end());
            piles.pop_back();
        }
        return ans;
    }
};