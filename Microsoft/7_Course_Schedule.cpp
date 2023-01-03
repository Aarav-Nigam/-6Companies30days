/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/course-schedule/description/
*/
#include <vector>
using namespace std;
class Solution {
public:
//We will use the concept of topological sort to solve this queation

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //Declaring both graph and the InDegr Array
        vector<vector<int>> graph(n,vector<int>());
        vector<int> InDegr(n);
        for(vector<int> i:prerequisites){
            if(i[0]==i[1]) return false;
            graph[i[1]].push_back(i[0]);
            InDegr[i[0]]++;
        }

        //After calculating Indegree we will apply Toplogical Sort 
        //If we can do the sort than return true
        // else false
        for(int i=0;i<n;i++){
            int j=0;
            while(j<n){
                if(!InDegr[j]) break;
                j++;
            }
            if(j==n) return false;
            InDegr[j]--;
            for(int k:graph[j]){
                InDegr[k]--;
            }
        }
        return true;
    }
};