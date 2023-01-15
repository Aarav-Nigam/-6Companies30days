/*
Name:Aarav Nigam
Question Link:https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
*/
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int findKthNumber(int n, int k) {
		int result = 1;
		k--;
		while (k > 0) {
			const int delta = helper(result, result + 1, n);
			if (k >= delta) {
				result++;
				k -= delta;
			}
			else {
				result *= 10;
				k--;
			}
		}
		return result;
	}
private:
	int helper(size_t lb, size_t ub, const size_t n) {
		int result = 0;
		while (lb <= n) {
			result += min(n + 1, ub) - lb;
			lb *= 10;
			ub *= 10;
		}
		return result;
	}
};