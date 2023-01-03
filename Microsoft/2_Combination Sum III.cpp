/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/combination-sum-iii/description/
*/
#include<stack>
#include<vector>
#include<string>
#include<numeric>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans; //Global vector to store all correct answers

    void helper(vector<int> A,int k,int n,int num){
        if(k==0){
            //numeric lib has the accumulate function
            if(accumulate(A.begin(),A.end(),0)==n){  //On k==0(all numbers taken) we will check sum using this builtin function and we will compare it with the required answer
                ans.push_back(A);
            }
            return;
        }
        if(num>9) return;
        helper(A,k,n,num+1);  // Function call if we don't choose num in our answer
        A.push_back(num); 
        helper(A,k-1,n,num+1); //Function call if we choose the num in our answer
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> A;  //This vector will store the answer temporaily
        helper(A,k,n,1); 
        return ans;
    }
};