/*
Name: Aarav Nigam
Link:https://leetcode.com/problems/number-of-closed-islands/
*/
using namespace std;
#include<vector>
#include<algorithm>
class Solution {
public:
//Firstly sink all islands connected to boundary
//Then count the rest of the islands
    int n,m;
    void sink(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==1) return;
        grid[i][j]=1;
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        for(vector<int> k:dirs){
            if(i+k[0]>=0 && i+k[0]<n && j+k[1]>=0 && j+k[1]<m){
                sink(grid,i+k[0],j+k[1]);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) sink(grid,i,0);
            if(grid[i][m-1]==0) sink(grid,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0) sink(grid,0,i);
            if(grid[n-1][i]==0) sink(grid,n-1,i);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    sink(grid,i,j);
                }
            }
        }
        return ans;
    }
};