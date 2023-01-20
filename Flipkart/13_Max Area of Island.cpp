/*
Name:Aarav Nigam
Link:https://leetcode.com/problems/max-area-of-island/
*/
#include<vector>
using namespace std;
class Solution {
public:
    int Area(vector<vector<int>>& grid,int m,int n,int i,int j){
        if(grid[i][j]==0) return 0;
        vector<vector<int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        int ans=1;
        grid[i][j]=0;
        for(vector<int> k:dirs){
            if(i+k[0]<m && i+k[0]>=0 && j+k[1]<n && j+k[1]>=0){
                ans+=Area(grid,m,n,i+k[0],j+k[1]);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0;
        int m,n;
        m=grid.size();
        n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    area=max(Area(grid,m,n,i,j),area);
                }
            }
        }
        return area;
    }
};