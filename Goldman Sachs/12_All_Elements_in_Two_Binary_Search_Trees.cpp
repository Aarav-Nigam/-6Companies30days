/*Name:Aarav Nigam
https://leetcode.com/problems/invalid-transactions/
*/
#include<vector>
#include<map>
#include<queue>
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
    void inorder(TreeNode* T,queue<int>& Q){
        if(T != nullptr){
            inorder(T->left,Q);
            Q.push(T->val);
            inorder(T->right,Q);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> Q1,Q2;
        vector<int> ans;
        inorder(root1,Q1);inorder(root2,Q2);
        while(!Q1.empty() && !Q2.empty()){
            if(Q1.front()<Q2.front()){
                ans.push_back(Q1.front());Q1.pop();
            }
            else{
                ans.push_back(Q2.front());Q2.pop();
            }
        }
        while(!Q1.empty()){
            ans.push_back(Q1.front());Q1.pop();
        }
        while(!Q2.empty()){
            ans.push_back(Q2.front());Q2.pop();
        }
        return ans;
    }
};