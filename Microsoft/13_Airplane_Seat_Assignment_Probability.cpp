/*
Name:Aarav Nigam
Link to Problem:
https://leetcode.com/problems/airplane-seat-assignment-probability/description/
*/
class Solution {
public:
/*It is a probability question 
Try calculating for n=2,3,4,5 to notice the pattern 
This happens because it makes kind of a cycle*/
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1;
        else return 0.5;
    }
};