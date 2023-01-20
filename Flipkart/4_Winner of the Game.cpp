/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/find-the-winner-of-the-circular-game/
*/
#include<vector>
using namespace std;
class Solution {
/*
Better Solution => 
class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   
    }
};
*/

public:
    int findTheWinner(int n, int k) {
        vector<int> vis(n,0);
        int ptr=0;
        for(int i=0;i<n-1;i++){
            int d=k;
            while(d--){
                if(vis[ptr]!=0){
                    d++;
                }
                ptr=(ptr+1)%n;
            }
            if(ptr==0) vis[n-1]=1;
            else vis[ptr-1]=1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) return i+1;
        }
        return 0;
    }
};