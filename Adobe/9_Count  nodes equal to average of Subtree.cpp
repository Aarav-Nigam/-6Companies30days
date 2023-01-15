/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int count=0;
    vector<int> avr(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        vector<int> L=avr(root->left);
        vector<int> R=avr(root->right);
        if(((L[0]+R[0]+root->val)/(L[1]+R[1]+1))==root->val) count++;
        return {L[0]+R[0]+root->val,(L[1]+R[1]+1)};
    }
    int averageOfSubtree(TreeNode* root) {
        count=0;
        avr(root);
        return count; 
    }
};