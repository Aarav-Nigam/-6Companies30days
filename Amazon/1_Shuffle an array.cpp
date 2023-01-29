/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/shuffle-an-array/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> Orig;
    Solution(vector<int>& nums) {
        Orig=nums;
    }
    
    vector<int> reset() {
        return Orig;
    }
    
    vector<int> shuffle() {
        vector<int> result(Orig);
        for (int i = 0;i < result.size();i++) {
            int pos = rand()%(result.size()-i);
            swap(result[i+pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */