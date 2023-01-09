/*Name:Aarav Nigam
https://leetcode.com/problems/maximum-good-people-based-on-statements/
*/
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    //Here we are checking all possible configurations (i.e. 2^15) to check if they are valid or not 
    bool valid(int cur,int n,vector<vector<int>>& S){
        for(int i = 0; i < n; i++)
                if(cur & 1 << n-1-i)
                    for(int j = 0; j < n; j++)
                        if(S[i][j] != 2 && S[i][j] != bool(cur & 1 << n-1-j)) return false;
            return true;
    }
    int maximumGood(vector<vector<int>>& S) {
        int n = S.size(),ans = 0;
        int N=1<<n;
        for(int i = 0; i <N; i++)                   // bits in i denotes person configuration
            if(valid(i,n,S)) ans = max(ans, __builtin_popcount(i));    // update ans if valid config
        return ans;
    }
};