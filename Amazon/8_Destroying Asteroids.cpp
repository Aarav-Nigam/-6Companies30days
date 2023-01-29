/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/destroying-asteroids/
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long m=mass;
        sort(asteroids.begin(),asteroids.end());
        int l=asteroids.size();
        for(int i=0;i<l;i++){
            if(asteroids[i]<=m){
                m+=asteroids[i];
            }
            else{
                return false;
            }
        }
        return true;
    }
};