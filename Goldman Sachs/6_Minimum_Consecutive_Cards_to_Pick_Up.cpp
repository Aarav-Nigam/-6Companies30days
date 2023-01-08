/*
Name:Aarav Nigam
https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
*/
/*
traverse through the array and maintain the smallest distance between same nums(by using a map which holds last appearance of any number)
return ans
*/
#include<math.h>
#include<vector>
#include<map>

using namespace std;
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,int> m;
        int ansI=INT_MAX;
        int n=cards.size();
        for(int i=0;i<n;i++){
            if(m.find(cards[i])==m.end()){
                m[cards[i]]=i;
            }
            else{
                ansI=min(ansI,i-m[cards[i]]);
                m[cards[i]]=i; 
            }
        }
        if(ansI==INT_MAX) return -1;
        else return ansI+1;
    }
};