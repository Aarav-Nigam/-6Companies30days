/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/fruit-into-baskets/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
        int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j,ans=0;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            while(count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};