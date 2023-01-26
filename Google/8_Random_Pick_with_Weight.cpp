/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/random-pick-with-weight/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int ind : w){
            if(s.empty())
                s.push_back(ind);
            else
            //Storing the new element after last index elements space
            //[1,3]=>{1,0,0,3}
            //Now we can get the value by taking uppwe bound
                s.push_back(ind + s.back());
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int index = rand() % x;//getting random index
        auto it = upper_bound(s.begin(), s.end(),index);
        return it - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */