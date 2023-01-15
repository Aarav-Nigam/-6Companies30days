/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/maximum-matrix-sum/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
//Main objective is to shift one negative sign to smallest number rest negative signs will cancel each other(if odd negative numbers)
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        long long sum = 0;
        int negCount = 0;
        int smallestMin = INT_MAX;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                sum += abs(matrix[i][j]); //Add all the numbers
                
                if(matrix[i][j] < 0)
                    negCount++; //keep track of count of -ve numbers
                
				//keep track of the smallest number which can be negative
                smallestMin = min(smallestMin, abs(matrix[i][j]));
            }
        }
        
        return negCount%2 == 0 ? sum : sum-2*smallestMin;
		/*		
			Why (sum-2*smallestMin) ????
				In simple words : You had first added that number, 
				so you need to subtract that addition and also in the
				end, you need to reduce the sum with that number.
				That's why we have to substract 2 times.
				See with the example below :
				[1,   2, 3]
				[-1, -2,-3]
				[1,   2, 3]
			
			
				Over all Sum "S"(all elements with abs value) = 18
				Negative count = 3 which is odd
				Smallest number which can be negative is "Min"= 1

				so, 
				[1,   2, 3]
				[-1,  2, 3]
				[1,   2, 3]

				Now, final sum "F" = 1 + 2 + 3 + (-1) + 2 + 3 + 1 + 2 + 3 = 16

				So, final result "F" = "S" - 2*Min  (i.e. 18 - 2*1) = 16
		*/
    }
};