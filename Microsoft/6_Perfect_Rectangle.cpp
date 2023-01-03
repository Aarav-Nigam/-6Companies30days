/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/perfect-rectangle/description/
*/
#include <vector>
#include <map>
#include <cmath>
using namespace std;
class Solution {
public:
//This question is based on intuition and knowledge about the coordinate plane
/*If it is a valid rectangle, all interior points should have count 0, bootom left and top right most point should have value 1,
 and top left and bottom right should have count -1. If it is different than this, it is not a perfect rectangle.*/

 //The above statement can be checked by drawing on paper
 //Here we implemented this with the help of map and traversing it after it.
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        map<pair<int,int>,int> m;
        for(vector<int> i:rectangles){
            m[{i[0],i[1]}]++;
            m[{i[2],i[3]}]++;
            m[{i[0],i[3]}]--;
            m[{i[2],i[1]}]--;
        }
        int count=0;
        for(auto i:m){
            if(i.second!=0){
                if(abs(i.second)!=1){
                    return false;
                }
                else{
                    count++;
                }
            }
        }
        return count==4;
    }
};