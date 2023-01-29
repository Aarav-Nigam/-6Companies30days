/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int a=INT_MAX;
        for(int i:right){
            a=min(i,a);
        }
        int b=INT_MIN;
        for(int i:left){
            b=max(b,i);
        }
        return max(n-a,b);
    }
};