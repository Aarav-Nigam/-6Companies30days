/*
Name:Aarav Nigam
https://leetcode.com/problems/number-of-boomerangs/
*/
/*
take no of equal sides 
and add nP2 for all sides to answer to count all permutations
*/
#include<math.h>
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    double d(vector<int> a,vector<int> b){
        return sqrt(pow(a[0]-b[0],2)+pow(a[1]-b[1],2));
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        map<double,int> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                m[d(points[i],points[j])]++;
            }
            for(auto i:m){
                if(i.second>1){
                    ans+=(i.second*(i.second-1));
                }
            }
            m.clear();
        }
        
        return ans;
    }
};
