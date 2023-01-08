/*Name:Aarav Nigam
https://leetcode.com/problems/number-of-people-aware-of-a-secret/
*/
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    int M=1e9+7;
    int d,f;
    vector<long> dp;
    long helper(int n){
        if(!n) return  0;
        if(dp[n]!=-1) return dp[n];
        long res=1;
        for(int i=d;i<f;i++){
            if(n-i>=0) res+=helper(n-i);
            res%=M;
        }
        return dp[n]=res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        d=delay;f=forget;
        dp.resize(n+1,-1);
        return (helper(n)-helper(n-forget)+M)%M;
    }
};