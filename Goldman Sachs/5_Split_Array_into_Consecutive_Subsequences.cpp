/*
Name:Aarav Nigam
https://leetcode.com/problems/split-array-into-consecutive-subsequences/
*/
/*
Maintain two maps
1) With availaibility data of all numbers
2) Set of all groups and their requirements
*/
#include<math.h>
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> M,G;
        int n=nums.size();
        for(int i:nums) M[i]++;
        for(int i:nums){
            if(M[i]>0){
                if(G[i]==0){
                    if(M[i+1] && M[i+2]){
                        G[i+3]++;
                        M[i]--;M[i+1]--;M[i+2]--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    G[i]--;
                    M[i]--;
                    G[i+1]++;
                }
            }
        }
        return true;
    }
};