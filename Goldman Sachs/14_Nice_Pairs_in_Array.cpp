/*Name:Aarav Nigam
https://leetcode.com/problems/count-nice-pairs-in-an-array/
*/
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    long M=1000000007;
    int countNicePairs(vector<int>& nums) {
        map<long,long> m;
        for(int i:nums){
            string temp=to_string(i);
            reverse(temp.begin(),temp.end());
            m[stoi(temp)-i]++;
        }
        long ans=0;
        for(auto i:m){
            ans=(ans%M +((i.second*(i.second-1))/2)%M)%M;
        }
        return ans;
    }
};