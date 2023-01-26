/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/maximum-compatibility-score-sum/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        vector<int> pos;
        int m=students.size();
        for(int i=0;i<m;i++) pos.push_back(i);
        do{
            int curr = 0;
            for(int i = 0;i<m; i++)
                for(int j=0;j<students[pos[i]].size();j++)
                    curr += (students[pos[i]][j] == mentors[i][j]);
            ans = max(ans, curr);
        } while(next_permutation(pos.begin(), pos.end()) );
        return ans;
    }
};